class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int max_area = 0;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (matrix[r][c] == '1') {
                    heights[c] += 1;
                } else {
                    heights[c] = 0;
                }
            }
            max_area = max(max_area, largestRectangleArea(heights));
        }

        return max_area;
    }

private:
    int largestRectangleArea(const vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int max_area = 0;

        for (int i = 0; i <= n; ++i) {
            int curr = (i == n) ? 0 : heights[i];
            while (!st.empty() && curr < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int w = st.empty() ? i : (i - st.top() - 1);
                max_area = max(max_area, h * w);
            }
            st.push(i);
        }

        return max_area;
    }
};
