/*

height = [4 2 0 3 2 5]
h_left = [0 4 4 4 4 5]
h_right= [5 5 5 5 5 0]
water  = [0 2 4 1 2 0]

*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total_water = 0;
        vector<int> greater_in_left(n, 0);
        vector<int> greater_in_right(n, 0);

        greater_in_left[0] = height[0];
        for(int i=1; i<n; i++) {
            greater_in_left[i] = max(greater_in_left[i-1], height[i]);
        }

        greater_in_right[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--) {
            greater_in_right[i] = max(greater_in_right[i+1], height[i]); 
        }

        for(int i=0; i<n; i++) {
            total_water += min(greater_in_right[i], greater_in_left[i]) - height[i];
        }
        return total_water;
    }
};
