class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        int n = nums1.size(), m = nums2.size();
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        for(int i = 0; i < n; i++)
        {
            if(i > 0 && nums1[i] == nums1[i - 1])
                continue;
            bool flag = true;
            for(int j = 0; j < m && flag; j++)
                if(nums1[i] == nums2[j])
                    flag = false;
            if(flag)
                ans[0].push_back(nums1[i]);
        }
        
        for(int i = 0; i < m; i++)
        {
            if(i > 0 && nums2[i] == nums2[i - 1])
                continue;
            bool flag = true;
            for(int j = 0; j < n && flag; j++)
                if(nums2[i] == nums1[j])
                    flag = false;
            if(flag)
                ans[1].push_back(nums2[i]);
        }
        
        return ans;
    }
};