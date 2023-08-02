class Solution
{
    void f(vector<vector<int>> &ans, vector<int> &curr, vector<int> &nums, int idx)
    {
        if (idx == nums.size())
        {
            ans.push_back(curr);
            return;
        }

        for (int i = idx; i < nums.size(); i++)
        {
            curr.push_back(nums[i]);
            swap(nums[idx], nums[i]);
            f(ans, curr, nums, idx + 1);
            swap(nums[idx], nums[i]);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> curr;
        f(ans, curr, nums, 0);
        return ans;
    }
};