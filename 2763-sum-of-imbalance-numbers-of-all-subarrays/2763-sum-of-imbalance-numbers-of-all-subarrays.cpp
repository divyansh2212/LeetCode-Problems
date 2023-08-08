class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            set<int> st;
            set<pair<int, int>> pairs;
            st.insert(nums[i]);
 
            for(int j = i + 1; j < n; j++)
            {
                int first = -1, second = -1;
                if(st.find(nums[j]) != st.end()) {
                    ans += pairs.size();
                    continue;
                }
                    
                st.insert(nums[j]);
                auto it = st.upper_bound(nums[j]);
                if(it != st.end())
                {
                    second = *it;
                    if(second - nums[j] > 1) {
                        pairs.insert({nums[j], second});
                    }
                }
                it = st.find(nums[j]);
                if(it != st.begin()) {
                    it--;
                    first = *it;
                    if(nums[j] - first > 1) {
                        pairs.insert({first, nums[j]});
                    }
                }
                pairs.erase({first, second});
                ans += pairs.size();
            }
        }
        
        return ans;
    }
};