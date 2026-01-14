class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> numFreq;

        for(int &i : nums) {
            if(numFreq[i]) return true;
            numFreq[i] = true;
        }
        return false;
    }
};
