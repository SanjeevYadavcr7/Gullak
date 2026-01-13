class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groupedAnagrams;
        unordered_map<string, vector<string>> stringsMap;

        for(string str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            stringsMap[key].push_back(str); 
        }

        for(const auto&pair : stringsMap) {
            groupedAnagrams.push_back(pair.second);
        }
        return groupedAnagrams;
    }
};
