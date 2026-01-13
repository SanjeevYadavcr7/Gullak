class Solution {
public:
    /* 
        Naive: O(N^2)
        Optmizied Approach: O(N) | O(N)

    */

    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> freqMap;

        for(int i=0; i<n; i++) {
            int req_num = target - nums[i];
            if(freqMap.find(req_num) != freqMap.end()) {
                return {i, freqMap[req_num]};
            }
            freqMap[nums[i]] = i;
        }

        return {};
    }
};
