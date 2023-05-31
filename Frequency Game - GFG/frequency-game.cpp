//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        
        unordered_map<int, int> hashTable;
        
        for(int i = 0; i < n; i++)
            hashTable[arr[i]]++;
        
        int ans = -1;
        int freq = 1e9;
        
        for(auto &it : hashTable)
        {
            if(it.second < freq) 
            {
                freq = it.second;
                ans = it.first;
            }
            else if(freq == it.second && it.first > ans)
                ans = it.first;
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends