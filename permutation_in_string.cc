class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if(n1 > n2) return false;

        vector<int> freq_map1(26, 0);
        vector<int> freq_map2(26, 0);

        for(char ch : s1) freq_map1[ch - 'a']++;
        for(int i=0; i<n1; i++) freq_map2[s2[i] - 'a']++;

        if(freq_map1 == freq_map2) return true;

        for(int i=n1; i<n2; i++) {
            freq_map2[s2[i-n1] - 'a']--;
            freq_map2[s2[i] - 'a']++;
            if(freq_map1 == freq_map2) return true;
        }
        return false;
    }
};
