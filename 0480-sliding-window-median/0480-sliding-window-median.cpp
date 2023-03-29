class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<double> ans;
        multiset<int> st1, st2;
        
        // int i = 0, j = 0;
        
        for(int i = 0; i < k; i++)
            st2.insert(nums[i]);
        
    
        while (st1.size() < st2.size())
        {
            auto it = st2.begin();
            int val = *it;
            st1.insert(val);
            st2.erase(it);
        }
        
        int i = 0, j = k - 1;
            
        while(j < n)
        {
            if(k % 2)
            {
                auto it1 = st1.end();
                it1--;
                int val1 = *it1;
                ans.push_back(val1);
            }
            else
            {
                auto it1 = st1.end();
                it1--;
                int val1 = *it1;
                auto it2 = st2.begin();
                int val2 = *it2;
                ans.push_back(double(val1 +0LL+ val2) / 2.0);
            }
            
            auto it1 = st1.find(nums[i]);
            auto it2 = st2.find(nums[i]);
            
            if(it1 != st1.end())
            {
                st1.erase(it1);
            }
            else
                st2.erase(it2);
            
            i++, j++;
            
            if(j < n)
            {
                st2.insert(nums[j]);
                
                while (st1.size() < st2.size())
                {
                    auto it = st2.begin();
                    int val = *it;
                    st1.insert(val);
                    st2.erase(it);
                }
                
                while(st1.size() && st2.size())
                {
                    auto it1 = st1.end(); it1--;
                    auto it2 = st2.begin();
                    int val1 = *it1, val2 = *it2;
                    
                    if(val1 > val2)
                    {
                        st1.erase(it1);
                        st2.erase(it2);
                        st1.insert(val2);
                        st2.insert(val1);
                    }
                    
                    else
                        break;
                }
            }
            
        }
        
        return ans;
    }
};