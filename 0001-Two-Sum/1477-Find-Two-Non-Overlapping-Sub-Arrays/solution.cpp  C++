class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> min_len(n, INT_MAX);
        
        int left = 0, current_sum = 0;
        int ans = INT_MAX;
        
        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];
            
            while (current_sum > target && left <= right) {
                current_sum -= arr[left++];
            }
            
            if (current_sum == target) {
                int curr_len = right - left + 1;
                
                if (left > 0 && min_len[left - 1] != INT_MAX) {
                    ans = min(ans, curr_len + min_len[left - 1]);
                }
                
                if (right > 0) {
                    min_len[right] = min(min_len[right - 1], curr_len);
                } else {
                    min_len[right] = curr_len;
                }
            } else {
                if (right > 0) {
                    min_len[right] = min(min_len[right - 1]);
                }
            }
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};
