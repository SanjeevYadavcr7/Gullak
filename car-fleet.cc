/*
pos   = [10 8 0 5 3]
speed = [2  4 1 1 3]
      = [12 12 1 6 6]

pos   = [4 1 0 7]
      = [2 2 1 1]
      -------------
      = [ 6   3  1  8  ]
      = [ 8   5  2  9  ]
      = [ 10  8  3  10 ]

*/
class Solution {
    using Pair = pair<int, int>; 
public:
    static bool sortByPosition(Pair& a, Pair& b) {
        return a.first > b.first;
    }

    bool willCarsMeet(Pair& car1, Pair& car2, int target) {
        float time_for_car1 = float(target - car1.first) / car1.second;
        float time_for_car2 = float(target - car2.first) / car2.second;
        return time_for_car1 <= time_for_car2; 
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        stack<Pair> stk;
        vector<Pair> cars;

        for(int i=0; i<n; i++) cars.push_back({position[i], speed[i]});

        sort(cars.begin(), cars.end(), sortByPosition);

        for(int i=0; i<n; i++) {
            Pair curr_car = cars[i];
            if(stk.empty()) {
                stk.push(curr_car);
                continue;
            }
            Pair prev_car = stk.top();
            if(!willCarsMeet(curr_car, prev_car, target)) stk.push(curr_car);
        }
        return stk.size();
    }
};
