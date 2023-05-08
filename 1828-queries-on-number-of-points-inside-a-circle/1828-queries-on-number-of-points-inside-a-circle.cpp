class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n = points.size(), q = queries.size();
        vector<int> ans(q, 0);
        
        for(int i = 0; i < q; i++)
        {
            int x = queries[i][0], y = queries[i][1], r = queries[i][2];
            
            for(int j = 0; j < n; j++)
            {
                int x1 = points[j][0], y1 = points[j][1];
                if((x - x1) * (x - x1) + (y - y1) * (y - y1) <= r*r)
                    ans[i]++;
            }
        }
        
        return ans;
    }
};