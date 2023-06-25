class Solution {
    
    const int mod = 1e9 + 7;
    
    int routes(int loc, vector<int>& locations, int &finish, int fuel, vector<vector<int>> &dp)
    {
        int n = locations.size();
        
        if(dp[loc][fuel] != -1)
            return dp[loc][fuel];
        
        int ans = 0;
        
        if(loc == finish)
            ans++;
        
        for(int i = 0; i < n; i++)
        {
            if(loc == i)
                continue;
            if(abs(locations[i] - locations[loc]) <= fuel) {
                ans = (ans + 0LL + routes(i, locations, finish, fuel - abs(locations[i] - locations[loc]), dp)) % mod;
            }
        }
        
        return dp[loc][fuel] = ans;
    }
    
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n + 1, vector<int> (fuel + 1, -1));
        return routes(start, locations, finish, fuel, dp);
        
    }
};