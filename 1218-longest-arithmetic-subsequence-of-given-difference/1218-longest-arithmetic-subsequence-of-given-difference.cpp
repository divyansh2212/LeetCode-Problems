class Solution {
    
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        int ans = 1;
        unordered_map<int, int> dp;
        
        for(int i = 0; i < n; i++ ){
            ans = max(ans, 1 + dp[arr[i] - difference]);
            dp[arr[i]] = 1 + dp[arr[i] - difference];
        }
        
        return ans;
    }
};