//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        vector<char> lowercases;
        vector<char> uppercases;
        
        for(int i = 0; i < n; i++)
        {
            if(str[i] >= 'a' && str[i] <= 'z')
                lowercases.push_back(str[i]);
            else
                uppercases.push_back(str[i]);
        }
        
        sort(lowercases.begin(), lowercases.end());
        sort(uppercases.begin(), uppercases.end());
        
        int j = 0, k = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] = lowercases[j];
                j++;
            }
            else
            {
                str[i] = uppercases[k];
                k++;
            }
        }
        
        return str;
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
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends