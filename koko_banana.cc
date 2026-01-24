class Solution {
public:
    bool canEatBananas(vector<int>& piles, int& time_limit, long long& k) {
        long long time_taken = 0;
        for(int& pile : piles) {
            time_taken += pile/k;
            if(pile % k > 0) time_taken += 1;
        }
        return time_taken <= time_limit;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int min_speed = INT_MAX;
        int beg = 1;
        int end = *max_element(piles.begin(), piles.end());

        while(beg <= end) {
            long long mid = beg + (end - beg) / 2;
            if(canEatBananas(piles, h, mid)) {
                if(mid < min_speed) min_speed = mid;
                end = mid-1;
            } else beg = mid+1;
        }
        return min_speed;
    }
};
