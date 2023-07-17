class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        
        for(auto &it : nums)
        {
            int cnt = 0;
            int num = it;
            while(st.find(num) != st.end()) {
                cnt++;
                st.erase(num);
                num = num + 1;
            }
            num = it - 1;
            while(st.find(num) != st.end()) {
                cnt++;
                st.erase(num);
                num = num - 1;
            }
            ans = max(ans, cnt);
        }
        
        return ans;
    }
};