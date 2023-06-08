class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) 
    {
        int ans= 0;
        for(int i=0; i < grid.size(); i++)
        {
            int right = grid[i].size()-1, left = 0;
            while(left <= right)
            {
                int mid = (left + right)/2;
                if(grid[i][mid] >= 0)
                {
                    left = mid+1;
                }
                else if(grid[i][mid] < 0)
                {
                    right = mid-1;
                }
            }
            ans += grid[i].size() - left;
        }
        return ans;
    }
};