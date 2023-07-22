class Solution {
    
    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};
    
    map<vector<int>, double> dp;
    
    double calc(int &n, int k, int i, int j)
    {
        if(i >= n || j >= n || i < 0 || j < 0)
            return 0;
        if(k == 0) {
            return 1;
        }
        
        if(dp.find({i, j, k}) != dp.end()) {
            return dp[{i, j, k}];
        }
        
        double ans = 0;
        for(int d = 0; d < 8; d++) {
            
            int x = i + dx[d], y = j + dy[d];
            ans += (calc(n, k - 1, x, y) / 8.0);   
        }
        
        return dp[{i, j, k}]=ans;
    }
    
public:
    double knightProbability(int n, int k, int row, int column) {
        
        return calc(n, k, row, column);
        
    }
};
