class Solution {
    
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        int n = nums.size();
        long long ans = 0;
        
        long long freq = 0;
        int element = nums[0];
        for(int i = 0; i < n; i++)
            freq += cost[i];
        
        vector<pair<int, int>> pairs;
        for(int i = 0; i < n; i++) {
            pairs.push_back({nums[i], cost[i]});
        }
        
        sort(pairs.begin(), pairs.end());
        long long currfreq = 0;
        for(int i = 0; i < n; i++)
        {
            if(currfreq <= freq / 2) {
                element = pairs[i].first;
            }
            currfreq += pairs[i].second;
        }
        
        for(int i = 0; i < n; i++) {
            ans += abs(nums[i] - element) * 1LL * cost[i];
        }
        // cout << element;
        return ans;
    }
};