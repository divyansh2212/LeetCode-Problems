//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
const int mod = 1e9 + 7;

long long calculate(int i, int j, int &n, int &m)
{
    long long ans = (n * m) - 1;
    if(i + 2 <= n && j + 1 <= m)
        ans--;
    if(i + 2 <= n && j - 1 >= 1)
        ans--;
    if(i - 2 >= 1 && j - 1 >= 1)
        ans--;
    if(i - 2 >= 1 && j + 1 <= m)
        ans--;
    if(j + 2 <= m && i + 1 <= n)
        ans--;
    if(j + 2 <= m && i - 1 >= 1)
        ans--;
    if(j - 2 >= 1 && i - 1 >= 1)
        ans--;
    if(j - 2 >= 1 && i + 1 <= n)
        ans--;
    return ans;
}

long long numOfWays(int n, int m)
{
    long long ways = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            ways = (ways + calculate(i, j, n, m)) % mod;
    
    return ways;
}