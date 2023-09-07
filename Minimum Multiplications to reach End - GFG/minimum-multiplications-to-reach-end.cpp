//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
    const int mod = 100000;
    
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int n = arr.size();
        
        queue<int> q;
        q.push(start);
        vector<bool> visit(1e5, 0);
        visit[start] = true;
        
        int steps = 0;
        
        while(!q.empty())
        {
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                auto front = q.front(); q.pop();
                if(front==end)
                    return steps;
                
                for(int x : arr) {
                    int num = (front * x) % mod;
                    if(visit[num] == false) {
                        visit[num] = true;
                        q.push(num);
                    }
                }    
                    
            }
            steps++;    
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends