// <--------------------Jai Shree Babosa-------------------->

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vint vector<int>
#define vll vector<long long>
#define inf INT_MAX
const int mod = 1e9 + 7;

class Solution
{

public:
    int maximizeWin(vector<int> &prizePositions, int k)
    {
        int n = prizePositions.size();

        vector<int> dp(n, 0);
        int start = 0;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            while (prizePositions[i] - prizePositions[start] > k)
                start++;
            
            dp[i] = i - start + 1;
            if (i > 0)
                dp[i] = max(dp[i], dp[i - 1]);
            
            ans = max(ans, i - start + 1);
            if(start > 0)
                ans = max(ans, dp[start - 1] + i - start + 1);
            
        }
        return ans;
    }
};