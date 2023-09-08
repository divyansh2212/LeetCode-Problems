//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/
#include<bits/stdc++.h>
class Solution {
public:
    int PalinArray(int a[], int n)
    {
    	// code here
    	for(int i = 0; i < n; i++) {
    	    vector<int> digits;
    	    while(a[i] > 0) {
    	        int rem = a[i] % 10;
    	        a[i] /= 10;
    	        digits.push_back(rem);
    	    }
    	    
    	    int a = 0, b = digits.size() - 1;
    	    while(a < b) {
    	        if(digits[a] != digits[b])
    	            return false;
    	        a++, b--;
    	    }
    	}
    	
    	return true;
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
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends