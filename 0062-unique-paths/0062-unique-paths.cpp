

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<int> prev(n, 0);
        prev[0] = 1;
        for (int i = 0; i < m; i++)
        {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (j > 0)
                    curr[j] += curr[j - 1];
                curr[j] += prev[j];
            }
            prev = curr;
        }

        return prev[n - 1];
    }
};