//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    string chooseandswap(string s){
        // Code Here
        int n = s.length();
        
        vector<int> hashTable(26, -1);
        for(int i = 0; i < n; i++)
        {
            if(hashTable[s[i] - 'a'] == -1)
                hashTable[s[i] - 'a'] = i;
        }
        
        for(int i = 0; i < n; i++)
        {
            for(char j = 'a'; j < s[i]; j++)
            {
                if(hashTable[j - 'a'] == -1)
                    continue;
                // cout << j << " " << i << "\n";
                if(hashTable[j - 'a'] > hashTable[s[i] - 'a'])
                {
                    // cout << j << " " << i;
                    char c1 = j;
                    char c2 = s[i];
                    for(int k = 0; k < n; k++)
                    {
                        if(s[k] == c1)
                            s[k] = c2;
                        else if(s[k] == c2)
                            s[k] = c1;
                    }
                    
                    return s;
                }
            }
        }
        
        return s;
    }
    
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}

// } Driver Code Ends