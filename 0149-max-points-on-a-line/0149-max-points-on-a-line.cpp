class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2)
            return n;
        
        int ans = 2;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int x1 = points[i][0], x2 = points[j][0], y1 = points[i][1], y2 = points[j][1];
                double slope = ((y2 - y1) * 1.0) / (x2 - x1);
                
                int curr = 2;
                
                for(int k = 0; k < n; k++)
                {
                    if(k == i || k == j)
                        continue;
                    int x3 = points[k][0], y3 = points[k][1];
                    
                    double slope2 = ((y3 - y1) * 1.0) / (x3 - x1);
                    
                    if(slope == slope2)
                        curr++;
                }
                
                ans = max(ans, curr);
            }
        }
        
        return ans;
    }
};