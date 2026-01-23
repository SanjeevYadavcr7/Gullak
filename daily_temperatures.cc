class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> res(n, 0);
        stack<int> num_index_stk;

        for(int i=0; i<n; i++) {
            while(!num_index_stk.empty() && temp[num_index_stk.top()] < temp[i]) {
                res[num_index_stk.top()] = i - num_index_stk.top();
                num_index_stk.pop();
            }
            num_index_stk.push(i);
        }

        return res;
    }
};
