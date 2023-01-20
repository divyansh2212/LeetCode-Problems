class Solution {
    
    void generate(int idx, vector<int> &nums, vector<int> &curr, set<vector<int>> &ans)
    {
        if(idx == nums.size())
        {
            if(curr.size() > 1)
                ans.insert(curr);
            return;
        }
        
        if(curr.size() == 0 || curr.back() <= nums[idx])
        {
            curr.push_back(nums[idx]);
            generate(idx + 1, nums, curr, ans);
            curr.pop_back();
        }
        generate(idx + 1, nums, curr, ans);
    }
    
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> curr;
        generate(0, nums, curr, ans);
        vector<vector<int>> subsets(ans.begin(), ans.end());
        return subsets;
    }
};