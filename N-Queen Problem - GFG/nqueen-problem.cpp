//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    
    bool diagRig(int i, int j, int &x, int &y)
    {
        while(i <= x && j <= y) {
            if(i == x && j == y)
                return false;
            i++; j++;
        }
        return true;
    }
    
    bool diagLef(int i, int j, int &x, int &y)
    {
        while(i <= x && j >= 1) {
            if(i == x && j == y)
                return false;
            i++; j--;
        }
        return true;
    }
    bool down(int i, int j, int &x, int &y)
    {
        while(i <= x) {
            if(i == x && j == y)
                return false;
            i++;
        }
        return true;
    }
    
    bool isValid(vector<int> &curr, int row, int col)
    {
        for(int i = 0; i < curr.size(); i++) {
            int currRow = i + 1, currCol = curr[i];
            if(!diagRig(currRow, currCol, row, col) || !diagLef(currRow, currCol, row, col) 
                || !down(currRow, currCol, row, col))
                return false;
        }
        return true;
    }
    
    void solve(int row, vector<vector<int>> &ans, vector<int> &curr, int &n)
    {
        if(row == n + 1) {
            ans.push_back(curr);
            return;
        }
        
        for(int col = 1; col <= n; col++)
        {
            if(isValid(curr, row, col)) {
                curr.push_back(col);
                solve(row + 1, ans, curr, n);
                curr.pop_back();
            }
        }
    }
    
public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        
        solve(1, ans, curr, n);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends