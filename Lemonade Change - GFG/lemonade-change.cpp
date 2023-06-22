//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int n, vector<int> &bills) {
        // code here
        int five = 0;
        int tens = 0;
        int twenty = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(bills[i] == 5) {
                five++;
            }
            else if(bills[i] == 10) {
                tens++;
                if(five == 0)
                    return false;
                else
                    five--;
            }
            else {
                twenty++;
                if(tens >= 1 && five >= 1) {
                    tens--; five--;
                }
                else if(five >= 3) {
                    five -= 3;
                }
                else
                    return false;
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends