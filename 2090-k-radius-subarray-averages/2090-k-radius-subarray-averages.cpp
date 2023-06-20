class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> ans(n, -1);
        
        int x = 2*k + 1;
        long long sum = 0;
        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + nums[i];
        
        for(int i = k; i <= n - 1 - k; i++)
        {
            long long curr = prefix[i + k];
            if(i - k - 1 >= 0)
                curr -= prefix[i - k - 1];
            curr /= x;
            ans[i] = curr;
        }

        return ans;
    }
};