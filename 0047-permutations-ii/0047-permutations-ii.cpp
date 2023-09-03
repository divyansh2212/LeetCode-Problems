class Solution {
    
    void solve(int idx, vector<int> &nums, set<vector<int>> &st)
    {
        int n = nums.size();
        if(idx == n) {
            st.insert(nums);
            return;
        }
        
        for(int i = idx; i < n; i++) {
            swap(nums[i], nums[idx]);
            solve(idx + 1, nums, st);
            swap(nums[i], nums[idx]);
        }
        
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> st;
        solve(0, nums, st);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};