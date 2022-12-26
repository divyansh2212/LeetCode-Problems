#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

int main()
 {
	//code
	int t;
	cin >> t;
	while(t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
            
        k = k % n;
        
        reverse(arr.begin(), arr.begin() + k);
        reverse(arr.begin() + k, arr.end());
        
        reverse(arr.begin(), arr.end());
        
        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
	return 0;
}