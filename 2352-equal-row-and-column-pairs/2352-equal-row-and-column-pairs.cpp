
class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int n = grid.size(), ans = 0;

        for (int i = 0; i < n; i++)
        {
            vector<int> row;
            for (int j = 0; j < n; j++)
                row.push_back(grid[j][i]);

            for (int k = 0; k < n; k++)
            {
                if (grid[k] == row)
                    ans++;
            }
        }
        return ans;
    }
};