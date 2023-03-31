class Solution {
public:
    #define mod (int)(1e9+7)
    bool CheckApple(int row1,int row2,int col1,int col2,vector<string>& pizza)
    {
        for(int i=row1;i<=row2;i++)
            for(int j=col1;j<=col2;j++)
                if(pizza[i][j]=='A') return true;

        return false;
    }
    int f(int i1,int j1,int i2,int j2,int k,vector<string>& pizza,vector<vector<vector<int>>>& dp)
    {
        if(k == 0)
            return 1;
        
        if(dp[i1][j1][k] != -1)
            return dp[i1][j1][k];
        int ans = 0;
        
        for(int i = i1; i <= i2-1; i++)
        {
            if(CheckApple(i1,i,j1,j2,pizza) && CheckApple(i+1,i2,j1,j2,pizza))
            {
                ans= (ans + f(i+1,j1,i2,j2,k-1,pizza,dp)) %mod;
            }
        }
        
        for(int j=j1;j<=j2-1;j++)
        {
            if(CheckApple(i1,i2,j1,j,pizza) && CheckApple(i1,i2,j+1,j2,pizza))
            {
                ans=(ans+f(i1,j+1,i2,j2,k-1,pizza,dp))%mod;
            }
        } 
        return dp[i1][j1][k]=ans;
    }
    int ways(vector<string>& pizza, int k) {
        int n=pizza.size(), m=pizza[0].length();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m ,vector<int>(k + 1, -1)));
        return f(0, 0, n-1, m-1, k-1, pizza, dp);
    }
};