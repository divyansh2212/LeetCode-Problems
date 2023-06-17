class Solution {
    
    map<pair<int, int>, int> dp;

    int solve(vector<int>& arr1, vector<int>& arr2, int idx1, int last)
    {
        int n = arr1.size();
        int m = arr2.size();
        
        if(idx1 == n)
            return 0;
        
        if(dp.find({idx1, last}) != dp.end())
            return dp[{idx1, last}];
        
        int replace = 1e9;
        int notreplace = 1e9;
        
        auto it = upper_bound(arr2.begin(), arr2.end(), last) - arr2.begin();
        if(it != m)
            replace = 1 + solve(arr1, arr2, idx1 + 1, arr2[it]);
        
        if(arr1[idx1] > last)
            notreplace = solve(arr1, arr2, idx1 + 1, arr1[idx1]);
        
        return dp[{idx1, last}] = min(replace, notreplace);
    }
    public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        
        int n = arr1.size();
        int m = arr2.size();
                
        sort(arr2.begin(), arr2.end());

        int ans = solve(arr1, arr2, 0, -1);
        
        if(ans >= 1e9)
            return -1;
        return ans;
    }
};