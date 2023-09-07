//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int maxProfit(vector<int>&price){
    
    int n = price.size();
    int first_buy = INT_MIN;
    int first_sell = INT_MIN;
    int sec_buy = INT_MIN;
    int sec_sell = INT_MIN;
    
    for(int i = 0; i < n; i++) {
        first_buy = max(first_buy, -price[i]);
        first_sell = max(first_sell, first_buy + price[i]);
        sec_buy = max(sec_buy, first_sell - price[i]);
        sec_sell = max(sec_sell, sec_buy + price[i]);
    }
    
    return sec_sell;
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends