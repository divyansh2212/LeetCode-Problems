//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int n, vector<int> arr) {
        // Code here
        
        unordered_map<int, int> hashTable;
        for(int i = 0; i < n; i++)
            hashTable[arr[i]]++;
        
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j * j <= arr[i]; j++)
            {
                if(j == 1)
                {
                    if(arr[i] == 1)
                    {
                        if(hashTable[1] > 1)
                        {
                            ans++;
                            break;
                        }
                    }
                    else
                    {
                        if(hashTable[1] > 0 || hashTable[arr[i]] > 1)
                        {
                            ans++;
                            break;
                        }
                    }
                }
                else if(arr[i] % j == 0 && (hashTable[j] > 0 || hashTable[arr[i] / j] > 0))
                {
                    ans++;
                    break;
                }
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends