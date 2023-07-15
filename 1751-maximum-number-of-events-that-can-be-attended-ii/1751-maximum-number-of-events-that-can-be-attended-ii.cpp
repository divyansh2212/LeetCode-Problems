class Solution {
    
    bool static comparator(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    
    map<vector<int>, int> dp;
    
    int solve(int idx, vector<vector<int>>& events, int k, int last)
    {
        int n = events.size();
        if(k == 0 || idx == n)
            return 0;
        
        if(dp.find({idx, k, last}) != dp.end())
            return dp[{idx, k, last}];
        
        int way1 = solve(idx + 1, events, k, last);
        int way2 = 0;
        if(events[idx][0] > last) {
            way2 = events[idx][2] + solve(idx + 1, events, k - 1, events[idx][1]);
        }
        
        return dp[{idx, k, last}] = max(way1, way2);
    }
    
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), comparator);
        return solve(0, events, k, 0);
    }
};