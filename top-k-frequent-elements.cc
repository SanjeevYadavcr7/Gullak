typedef pair<int,int> customPair;
class Solution {
public: 
    vector<int> topKFrequent(vector<int>& nums, int k){
        int n = nums.size();
        vector<int> k_freq_nums;
        unordered_map<int,int> freq;
        priority_queue<customPair, vector<customPair>, greater<>> box;


        for(int& i : nums) freq[i]++;
        for(auto it : freq){
            box.push({it.second,it.first});
            if(box.size() > k) box.pop();
        }

        while(!box.empty()){
            k_freq_nums.push_back(box.top().second);
            box.pop();
        }
        return k_freq_nums;
    }
