//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
    
        int n = s2.size();
        int m = s1.size();
        
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            bool found = false;
            for(int j = 0; j < m && !found; j++)
            {
                if(s2[i].length() <= s1[j].length())
                {
                    bool flag = true;
                    for(int k = 0; k < s2[i].length() && !found && flag; k++)
                    {
                        if(s2[i][k] != s1[j][k])
                            flag = false;
                    }
                    
                    if(flag)
                        found = true;
                    
                    flag = true;
                    for(int k = s2[i].length() - 1, l = s1[j].length() - 1; k >= 0 && !found && flag; k--, l--)
                    {
                        if(s2[i][k] != s1[j][l])
                            flag = false;
                    }
                    
                    if(flag)
                        found = true;
                }
            }
            if(found)
                ans++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends