class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        
        vector<long long> ans(5, 0);
        int sz = coordinates.size();
        map<pair<int, int>, int> blackCell;
        
        for(int i = 0; i < sz; i++)
        {
            int x = coordinates[i][0],
                y = coordinates[i][1];
            blackCell[{x, y}]++;
        }
        
        for(int i = 0; i < sz; i++)
        {
            int x = coordinates[i][0],
                y = coordinates[i][1];
            
            if(x - 1 >= 0 && y - 1 >= 0)
            {
                int curr = blackCell[{x, y}] + blackCell[{x - 1, y - 1}] + blackCell[{x - 1, y}] + blackCell[{x, y - 1}];
                ans[curr]++;
            }
            if(x - 1 >= 0 && y + 1 < n)
            {
                int curr = blackCell[{x, y}] + blackCell[{x - 1, y + 1}] + blackCell[{x - 1, y}] + blackCell[{x, y + 1}];
                ans[curr]++;
            }
            if(x + 1 < m && y + 1 < n)
            {
                int curr = blackCell[{x, y}] + blackCell[{x + 1, y + 1}] + blackCell[{x + 1, y}] + blackCell[{x, y + 1}];
                ans[curr]++;
            }
            if(x + 1 < m && y - 1 >= 0)
            {
                int curr = blackCell[{x, y}] + blackCell[{x + 1, y - 1}] + blackCell[{x + 1, y}] + blackCell[{x, y - 1}];
                ans[curr]++;
            }
        }
        
        long long total = (n  - 1) *1LL* (m - 1);
        for(int i = 1; i <= 4; i++)
        {
            ans[i] = ans[i] / i;
            total -= ans[i];
        }
        ans[0] = total;
        
        return ans;
    }
};