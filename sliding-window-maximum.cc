class Solution {
public:
    using intPair = pair<int, int>;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        deque<int> dq;
        vector<int> res;

        while(j < n) {
            int curr_num = nums[j];
            while(!dq.empty() && nums[dq.back()] < curr_num) dq.pop_back(); // remove smaller elements to maintain decreeasing order
            dq.push_back(j);

            if(i > dq.front()) dq.pop_front(); // increase left pointer to maintain window size

            if(j+1 >= k) {
                res.push_back(nums[dq.front()]);
                i++;
            }
            j++;
        }
        return res;
    }
};
