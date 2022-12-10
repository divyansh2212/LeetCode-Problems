//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    int n = num.length();
    stack<char> st;
    
    for(int i = 0; i < n; i++)
    {
        while(st.size() && st.top() > num[i] && k > 0)
        {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
            
    while(k > 0 && st.size())
    {
        st.pop();
        k--;
    }
    
    string result = "";
    while(!st.empty())
    {
        result.push_back(st.top());
        st.pop();
    }
    
    while(result.size() > 1 && result.back() == '0')
        result.pop_back();
    
    reverse(result.begin(), result.end());
    
    
    return result;
}