class Solution {
    
    const int mod = 1e9 + 7;
    
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int, long long> prefix;
        
        int i = 0, j = 0;
        
        while(i < n && j < m)
        {
            if(nums1[i] < nums2[j]) {
                if(i == 0) {
                    prefix[nums1[i]] = nums1[i];
                }
                else {
                    prefix[nums1[i]] = nums1[i] + prefix[nums1[i - 1]];
                }
                i++;
            }
            else if(nums1[i] > nums2[j]) {
                if(j == 0) {
                    prefix[nums2[j]] = nums2[j];
                }
                else {
                    prefix[nums2[j]] = nums2[j] + prefix[nums2[j - 1]];
                }
                j++;
            }
            else {
                if(i != 0 && j != 0) {
                    prefix[nums2[j]] = nums2[j] + prefix[nums2[j - 1]];
                    prefix[nums2[j]] = max(prefix[nums2[j]], nums1[i] + prefix[nums1[i - 1]]);    
                }
                else if(i == 0 && j == 0) {
                    prefix[nums2[j]] = nums1[i];
                }
                else if(i == 0) {
                    prefix[nums2[j]] = nums2[j] + prefix[nums2[j - 1]];
                }
                else {
                    prefix[nums2[j]] = nums1[i] + prefix[nums1[i - 1]];
                }
                i++, j++;
            }
        }
        
        while(i < n) {
            if(i == 0) {
                prefix[nums1[i]] = nums1[i];
            }
            else {
                prefix[nums1[i]] = nums1[i] + prefix[nums1[i - 1]];
            }
            i++;
        }
        
        while(j < m){
            if(j == 0) {
                prefix[nums2[j]] = nums2[j];
            }
            else {
                prefix[nums2[j]] = nums2[j] + prefix[nums2[j - 1]];
            }
            j++;
        }
        
        long long ans = 0;
        for(auto &it : prefix) {
            ans = max(ans, it.second);
        }
        
        return ans % mod;
    }
};