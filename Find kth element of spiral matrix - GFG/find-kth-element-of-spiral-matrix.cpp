//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    vector<int> findSpiralOrder(int a[][MAX], int n, int m)
    {
        int startCol = 0,
            endCol = m - 1,
            startRow = 0,
            endRow = n - 1;
        
        vector<int> ans;
        while(startRow <= endRow && startCol <= endCol)
        {
            for(int j = startCol; j <= endCol; j++) {
                ans.push_back(a[startRow][j]);
            }
            startRow++;
            
            for(int i = startRow; i <= endRow; i++) {
                ans.push_back(a[i][endCol]);
            }
            endCol--;
            
            for(int j = endCol; j >= startCol; j--) {
                ans.push_back(a[endRow][j]);
            }
            endRow--;
            
            for(int i = endRow; i >= startRow; i--) {
                ans.push_back(a[i][startCol]);
            }
            startCol++;
        }
        
        return ans;
    }
    
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX], int n, int m, int k)
    {
 		vector<int> spiralOrder = findSpiralOrder(a, n, m);
 		return spiralOrder[k - 1];
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends