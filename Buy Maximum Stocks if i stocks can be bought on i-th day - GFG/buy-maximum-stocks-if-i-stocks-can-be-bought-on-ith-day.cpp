//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pair<int, int>> stocks;
        for(int i = 0; i < n; i++)
            stocks.push_back({price[i], i + 1});
        
        sort(stocks.begin(), stocks.end());
        
        int number = 0;
        
        for(int i = 0; i < n; i++)
        {
            int pr = stocks[i].first, maxmFreq = stocks[i].second;
            int can_add = min(k / pr, maxmFreq);
            
            k -= (can_add * pr);
            number += can_add;
        }
        
        return number;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends