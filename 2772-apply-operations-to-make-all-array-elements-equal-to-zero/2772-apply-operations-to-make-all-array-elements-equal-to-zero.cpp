class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        if(k == 1)
            return true;
        int n = nums.size();
        
        vector<long long> diff(n + 1, 0);
        diff[0] += nums[0];
        diff[k] -= nums[0];
        
        for(int i = 1; i < n; i++)
        {
            diff[i] += diff[i - 1];
            
            if(diff[i] == nums[i])
                continue;
            else if(diff[i] > nums[i])
                return false;
            else {
                int currdiff = nums[i] - diff[i];
                diff[i] += currdiff;
                if(i + k > n)
                    return false;
                diff[i + k] -= currdiff;
            }
        }
        
        return true;
    }
};