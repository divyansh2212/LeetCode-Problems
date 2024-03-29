//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution
{
    public:
    string rearrangeString(string str)
    {
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> mp;
        
        for(auto &it : str) {
            mp[it]++;
        }
        
        for(auto &it : mp) {
            pq.push({it.second, it.first});
        }
        
        string ans = "";
        
        while(!pq.empty()) {
            auto front = pq.top();
            pq.pop();
            int freq = front.first;
            char ch = front.second;
            
            if(ans.size() && ans.back() == ch) {
                if(pq.size() == 0)
                    return "-1";
                auto front2 = pq.top();
                pq.pop();
                int freq2 = front2.first;
                char ch2 = front2.second;
                ans.push_back(ch2);
                freq2--;
                pq.push(front);
                if(freq2 > 0)
                    pq.push({freq2, ch2});
            }
            else {
                ans.push_back(ch);
                freq--;
                if(freq > 0)
                    pq.push({freq, ch});
            }
        }
        
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
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}
// } Driver Code Ends