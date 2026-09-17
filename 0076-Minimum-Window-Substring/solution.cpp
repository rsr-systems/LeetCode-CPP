class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) return "";
        
        vector<int> target_freq(128, 0);
        for (char c : t) {
            target_freq[c]++;
        }
        
        int required = 0;
        for (int count : target_freq) {
            if (count > 0) required++;
        }
        
        vector<int> window_freq(128, 0);
        int formed = 0;
        int left = 0;
        
        int min_len = INT_MAX;
        int start_idx = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            char c = s[right];
            window_freq[c]++;
            
            if (target_freq[c] > 0 && window_freq[c] == target_freq[c]) {
                formed++;
            }
            
            while (left <= right && formed == required) {
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    start_idx = left;
                }
                
                char left_char = s[left];
                window_freq[left_char]--;
                if (target_freq[left_char] > 0 && window_freq[left_char] < target_freq[left_char]) {
                    formed--;
                }
                left++;
            }
        }
        
        return min_len == INT_MAX ? "" : s.substr(start_idx, min_len);
    }
};
