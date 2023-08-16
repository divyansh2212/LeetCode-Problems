class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        multiset<int> st;
        for(int i = 0; i < k; i++) {
            st.insert(nums[i]);
        }
        
        vector<int> ans;
        int i = 0, j = k;
        while(j <= n)
        {
            auto it = st.end();
            it--;
            ans.push_back(*it);
            if(j == n)
                break;
            st.insert(nums[j]);
            auto it2 = st.find(nums[i]);
            st.erase(it2);
            i++;
            j++;
        }
        
        return ans;
    }
};