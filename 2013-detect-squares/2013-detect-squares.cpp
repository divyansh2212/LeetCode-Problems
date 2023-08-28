class DetectSquares {
    
    map<vector<int>, long> ps;
    
public:
    DetectSquares() {
        ps.clear();
    }
    
    void add(vector<int> point) {
        ps[point]++;
    }
    
    int count(vector<int> point) 
    {
        long ans = 0;
        int x1 = point[0], y1 = point[1];
        
        for(auto it : ps) {
            int x2 = it.first[0], y2 = it.first[1];
            if(x1 != x2 && y1 != y2 && abs(x1 - x2) == abs(y1 - y2)) {
                ans += it.second * ps[{x2, y1}] * ps[{x1, y2}];
            }
        }
        
        return ans;
    }
};
