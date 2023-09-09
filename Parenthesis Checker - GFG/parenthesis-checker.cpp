//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        int n = x.length();
        stack<char> st;
        
        for(int i = 0; i < n; i++) {
            if(x[i] == '(') {
                st.push(x[i]);
            }
            else if(x[i] == '[') {
                st.push(x[i]);
            }
            else if(x[i] == '{') {
                st.push(x[i]);
            }
            
            else if(x[i] == ')') {
                if(st.size() == 0)
                    return false;
                if(st.top() != '(')
                    return false;
                st.pop();
            }
            else if(x[i] == ']') {
                if(st.size() == 0)
                    return false;
                if(st.top() != '[')
                    return false;
                st.pop();
            }
            else if(x[i] == '}') {
                if(st.size() == 0)
                    return false;
                if(st.top() != '{')
                    return false;
                st.pop();
            }
        }
        
        return st.size() == 0;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends