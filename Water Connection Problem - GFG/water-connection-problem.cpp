//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b, vector<int> d)
    {
        vector<int> parent(n + 1, -1);
        vector<int> child(n + 1, -1);
        vector<int> diameters(n + 1, INT_MAX);
        
        for(int i = 0; i < p; i++)
        {
            int par = a[i], ch = b[i];
            parent[ch] = par;
            child[par] = ch;
            diameters[par] = min(diameters[par], d[i]);
            diameters[ch] = min(diameters[ch], d[i]);
        }
        
        vector<int> endNode;
        for(int i = 1; i <= n; i++)
        {
            if(child[i] == -1)
            {
                endNode.push_back(i);
            }
        }
        
        vector<vector<int>> ans;
        for(int i = 0; i < endNode.size(); i++)
        {
            int node = endNode[i], par = -1, dist = INT_MAX;
            while(node != -1)
            {
                dist = min(dist, diameters[node]);
                par = node;
                node = parent[node];
            }
            if(dist != INT_MAX)
            ans.push_back({par, endNode[i], dist});
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends