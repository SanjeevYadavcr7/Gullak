class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0) return 0;

        int i = 0, j = 1;
        int max_len = 1, len = 1;
        unordered_map<char, int> char_idx_map;

        char_idx_map[s[0]] = 1;
        while(j < n) {
            char ch = s[j];
            if(char_idx_map[ch] > 0) {
                int rep_char_idx = char_idx_map[ch] - 1;
                while(i <= rep_char_idx) {
                    char_idx_map[s[i]] = 0; // removing all chars from map until repeated character
                    i++;
                }
            } else {
                char_idx_map[ch] = j+1;
                max_len = max(max_len, j-i+1);
                j++;
            }
        } 
        return max_len;
    }
};
