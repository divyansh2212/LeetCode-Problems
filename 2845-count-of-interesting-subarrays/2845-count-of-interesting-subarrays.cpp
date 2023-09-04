class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        
        vector<long long> prefix(n + 1, 0);
        unordered_map<long long, long long> hm;
        hm[0] = 1;
        
        long long count = 0;
        
        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i];
            if(nums[i] % modulo == k)
                prefix[i + 1]++;
            
            long long target = (prefix[i + 1] - k + modulo) % modulo;
            
            count += hm[target];
            hm[prefix[i + 1] % modulo]++;
        }
        
        return count;
    }
};