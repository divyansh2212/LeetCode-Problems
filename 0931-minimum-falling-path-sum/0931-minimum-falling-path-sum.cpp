#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int f(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &dp)
    {
        int n = matrix.size();
        if (i == 0)
            return matrix[0][j];
        if (dp[i][j] != 1e9)
            return dp[i][j];

        int up = 1e8, upleft = 1e8, upright = 1e8;

        up = matrix[i][j] + f(matrix, i - 1, j, dp);
        if (j - 1 >= 0)
            upleft = matrix[i][j] + f(matrix, i - 1, j - 1, dp);
        if (j + 1 < n)
            upright = matrix[i][j] + f(matrix, i - 1, j + 1, dp);

        return dp[i][j] = min(up, min(upleft, upright));
    }

    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        // int ans = 1e8;
        // vector<vector<int>> dp(n, vector<int>(n, 1e9));
        // for (int j = 0; j < n; j++)
        //     ans = min(ans, f(matrix, n - 1, j, dp));
        // return ans;

        vector<int> prev(n, 1e9);

        for (int j = 0; j < n; j++)
            prev[j] = matrix[0][j];

        for (int i = 1; i < n; i++)
        {
            vector<int> curr(n, 1e9);
            for (int j = 0; j < n; j++)
            {
                int up = 1e8, upleft = 1e8, upright = 1e8;

                up = matrix[i][j] + prev[j];
                if (j - 1 >= 0)
                    upleft = matrix[i][j] + prev[j - 1];
                if (j + 1 < n)
                    upright = matrix[i][j] + prev[j + 1];

                curr[j] = min(up, min(upleft, upright));
            }
            prev = curr;
        }

        int ans = prev[0];
        for (int j = 0; j < n; j++)
            ans = min(ans, prev[j]);

        return ans;
    }
};