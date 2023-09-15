//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class DisjointSet {
  vector<int> parent;
  public:
  DisjointSet(int n) {
      parent.resize(n);
      for(int i = 0; i < n; i++)
        parent[i] = i;
  }
  
  int find_par(int n) {
    if(n == parent[n])
        return n;
    
    return parent[n] = find_par(parent[n]);
  }
  
  void Union(int u, int v) {
      u = find_par(u);
      v = find_par(v);
      parent[u] = v;
  }
  
};

class Solution{
  public:
    vector<vector<string>> Anagrams(vector<string>& arr) {
        //code here
        int n = arr.size();
        DisjointSet ds(n);
        for(int i = 0; i < n; i++) {
            vector<int> hsh1(26,0);
            for(auto &it : arr[i]) {
                hsh1[it - 'a']++;
            }
            for(int j = i + 1; j < n; j++) {
                if(ds.find_par(i) == ds.find_par(j))
                    continue;
                
                vector<int> hsh2(26,0);
                for(auto &it : arr[j]) {
                    hsh2[it - 'a']++;
                }
                
                if(hsh1 == hsh2) {
                    ds.Union(i, j);
                }
            }
        }
        
        unordered_set<int> st;
        vector<vector<string>> ans;
        
        for(int i = 0; i < n; i++) {
            int par1 = ds.find_par(i);
            if(st.find(par1) != st.end())
                continue;
            vector<string> curr;
            curr.push_back(arr[i]);
            for(int j = i + 1; j < n; j++) {
                int par2 = ds.find_par(j);
                if(par1 == par2) {
                    curr.push_back(arr[j]);
                }
            }
            st.insert(par1);
            ans.push_back(curr);
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}

// } Driver Code Ends