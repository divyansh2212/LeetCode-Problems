//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        // Code here
        vector<vector<int>> ans(n, vector<int> (m, -1));
        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(c[i][j] == 'W'){
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }
        
        int level = 0;
        while(!q.empty())
        {
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                auto front = q.front(); q.pop();
                int x = front.first, y = front.second;
                ans[x][y] = level;
                
                for(int d = 0; d < 4; d++)
                {
                    int x1 = x + dx[d], y1 = y + dy[d];
                    if(x1 >= 0 && y1 >= 0 && x1 < n && y1 < m && ans[x1][y1] == -1 && c[x1][y1] != 'N'){
                        ans[x1][y1] = 0;
                        q.push({x1, y1});
                    }
                }
            }
            level+=2;
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(c[i][j] == 'W' || c[i][j] == 'N' || c[i][j] == '.')
                    ans[i][j] = 0;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends