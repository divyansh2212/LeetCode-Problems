class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = speed.size();
        // vector<pair<int , double>> cars;
        
        priority_queue<pair<int, double>> cars;
        for(int i = 0; i < n; i++) {
            cars.push({position[i], ((target - position[i])*1.0) / speed[i]});
        }
        
        int fleet = 0;
        while(cars.size() > 1)
        {
            auto ahead = cars.top(); cars.pop();
            auto behind = cars.top(); cars.pop();
            
            if(ahead.second >= behind.second) {
                cars.push(ahead);
            }
            else {
                fleet++;
                cars.push(behind);
            }
        }
        
        if(cars.size()) fleet++;
        
        return fleet;
    }
};