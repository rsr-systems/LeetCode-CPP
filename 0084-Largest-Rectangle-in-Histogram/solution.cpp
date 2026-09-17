class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st; // Stores indices with strictly increasing heights
        int max_area = 0;
        
        for (int i = 0; i <= n; ++i) {
            // Use 0 as a sentinel height at index n to flush all remaining elements
            int curr_height = (i == n) ? 0 : heights[i];
            
            while (!st.empty() && curr_height < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                
                // If stack is empty, width extends all the way back to index 0
                int w = st.empty() ? i : (i - st.top() - 1);
                max_area = max(max_area, h * w);
            }
            
            st.push(i);
        }
        
        return max_area;
    }
};
