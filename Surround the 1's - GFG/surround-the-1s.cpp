//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& mat) {
        // Code here
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1) {
                    int cnt = 0;
                   if(i + 1 < n && j < m && mat[i + 1][j] == 0) cnt++;
                   if(i + 1 < n && j + 1 < m && mat[i + 1][j + 1] == 0) cnt++;
                   if(i + 1 < n && j - 1 >= 0 && mat[i + 1][j - 1] == 0) cnt++;
                   if(i < n && j + 1 < m && mat[i][j + 1] == 0) cnt++;
                   if(j + 1 < m && i - 1 >= 0 && mat[i - 1][j + 1] == 0) cnt++;
                   if(i - 1 >= 0 && mat[i - 1][j] == 0) cnt++;
                   if(i - 1 >= 0 && j - 1 >= 0 && mat[i - 1][j - 1] == 0) cnt++;
                   if(j - 1 >= 0 && mat[i][j - 1] == 0) cnt++;
                   
                   if(cnt > 0 && cnt % 2 == 0) ans++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends