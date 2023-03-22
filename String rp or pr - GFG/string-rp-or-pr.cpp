//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long solve(int x, int y, string s){
      int n = s.length();
      stack<char> st;
      long long ans = 0;
      
      if(x >= y)
      {
        for(int i = 0; i < n; i++)
        {
            if(st.empty())
                st.push(s[i]);
            else if(st.top() == 'p' && s[i] == 'r')
            {
                st.pop();
                ans += x;
            }
            else
                st.push(s[i]);
        }
        
        string bal = "";
        
        while(st.size())
        {
            char top = st.top();
            st.pop();
            bal.push_back(top);
        }
        
        for(int i = 0; i < bal.length(); i++)
        {
            if(st.empty())
                st.push(bal[i]);
            else if(st.top() == 'p' && bal[i] == 'r')
            {
                st.pop();
                ans += y;
            }
            else
                st.push(bal[i]);
        }
        
      }
      
      else
      {
          for(int i = 0; i < n; i++)
        {
            if(st.empty())
                st.push(s[i]);
            else if(st.top() == 'r' && s[i] == 'p')
            {
                st.pop();
                ans += y;
            }
            else
                st.push(s[i]);
        }
        
        string bal = "";
        
        while(st.size())
        {
            char top = st.top();
            st.pop();
            bal.push_back(top);
        }
        
        for(int i = 0; i < bal.length(); i++)
        {
            if(st.empty())
                st.push(bal[i]);
            else if(st.top() == 'r' && bal[i] == 'p')
            {
                st.pop();
                ans += x;
            }
            else
                st.push(bal[i]);
        }
      }
      
      
      return ans;
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends