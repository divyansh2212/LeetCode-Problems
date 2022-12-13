class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int longest = 0;
        if(nums[0] == 1)
            longest++;
        
        vector<pair<int, int>> pairs;
        pairs.push_back({nums[0], 1});
        for(int i = 1; i < n; i++)
        {
            if(pairs.back().first == nums[i])
                pairs.back().second++;
            else
                pairs.push_back({nums[i], 1});
            if(pairs.back().first == 1)
                longest = max(longest, pairs.back().second);
        }
        
        if(longest == n)
            longest--;
        
        for(int i = 1; i < pairs.size() - 1; i++)
        {
            if(pairs[i].first == 0 && pairs[i].second == 1)
            {
                if(pairs[i - 1].first == 1 && pairs[i + 1].first == 1)
                    longest = max(longest, pairs[i + 1].second + pairs[i - 1].second);
            }
        }
        
        return longest;
    }
};