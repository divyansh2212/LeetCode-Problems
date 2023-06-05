class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& points) {
        
        int n = points.size();
        
        int x1 = points[0][0], y1 = points[0][1], x2 = points[1][0], y2 = points[1][1];
        
        for(int i = 2; i < n; i++)
        {
            int x3 = points[i][0], y3 = points[i][1];
            
            if((y2 - y1)*(x3 - x1) == (y3 - y1)*(x2 - x1) )
                continue;
            return false;
        }
        
        return true;
    }
};