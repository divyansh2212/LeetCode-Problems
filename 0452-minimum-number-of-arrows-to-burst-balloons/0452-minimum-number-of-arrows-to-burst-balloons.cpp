class Solution {
    
    bool static comparator(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        
        sort(points.begin(), points.end(), comparator);
        
        int arrows = 1, end = points[0][1];
        
        for(int i = 1; i < n; i++)
        {
            if(points[i][0] <= end)
                continue;
            end = points[i][1], arrows++;
        }
        
        return arrows;
    }
};