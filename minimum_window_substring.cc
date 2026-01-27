class Solution {
public:
    string minWindow(string s, string t) {
        int s_size = s.size();
        int t_size = t.size();
        int have = 0, need;
        int l = 0, r = 0;
        string res = "";
        int len = INT_MAX;
        int start_idx = 0;
        unordered_map<char, int> t_map;
        unordered_map<char, int> s_map;
        
        for(char& ch : t) t_map[ch]++;

        need = t_map.size();

        if(s == t) return s;
        if(s_size < t_size) return "";

        while(r < s_size) {
            char ch = s[r];
            s_map[ch]++;

            if(t_map[ch] && s_map[ch] == t_map[ch]) have++; // freq of selected character in S matches T

            while(have == need) {
                int curr_len = r - l + 1;
                if(curr_len < len) len = curr_len, start_idx = l; // update resultant string
                s_map[s[l]]--;
                if(t_map[s[l]] && s_map[s[l]] < t_map[s[l]]) have--;
                l++;
            }
            r++;
        }

        if(len == INT_MAX) return "";
        res = s.substr(start_idx, len);
        return res;
    }
};
