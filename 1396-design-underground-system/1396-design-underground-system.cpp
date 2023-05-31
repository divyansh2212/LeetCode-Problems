class UndergroundSystem {
    map<int, pair<string, int>> passenger;
    map<pair<string, string>, vector<int>> travellingTimes;
public:
    UndergroundSystem() {
        passenger.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        passenger[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string source = passenger[id].first;
        int initialTime = passenger[id].second;
        passenger.erase(id);
        travellingTimes[{source, stationName}].push_back(t - initialTime);
    }
    
    double getAverageTime(string start, string end) {
        
        double total = 0;
        for(auto &it : travellingTimes[{start, end}])
            total += it;
        
        return total / travellingTimes[{start, end}].size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */