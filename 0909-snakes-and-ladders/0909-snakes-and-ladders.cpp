class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size(),k=1;
        vector<int> arr(n*n+1),dp(n*n+1,INT_MAX);
        dp[0]=0;
        dp[1]=0;
        bool flag=true;
        for(int i=n-1;i>=0;i--){
            if(flag)
                for(int j=0;j<n;j++)
                    arr[k++]=board[i][j];
            else
                for(int j=n-1;j>=0;j--)
                    arr[k++]=board[i][j];
            flag^=1;
        }
        queue<int> q;
        q.push(1);
        while(!q.empty()){
            auto k=q.front();
            q.pop();
            for(int i=1;i<=(6);i++){
                if(k+i>n*n) break;
                auto pos=k+i;
                if(arr[pos]!=-1) pos=arr[pos];
                if(dp[pos]>dp[k]+1){
                    dp[pos]=dp[k]+1;
                    q.push(pos);
                }
            }
        }
    
        return (dp[n*n]==INT_MAX?-1:dp[n*n]);
    }
};