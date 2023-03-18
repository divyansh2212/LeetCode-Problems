
class Solution
{
public:
    long long findScore(vector<int> &nums)
    {
        long long score = 0;
        int n = nums.size();
        
        set<pair<int, int>> st;
        
        for(int i = 0; i < n; i++)
        {
            st.insert({nums[i], i});
        }
        
        vector<bool> marked(n, false);
        
        for(auto &it : st)
        {
            int number = it.first, idx = it.second;
            if(marked[idx] == false)
            {
                score += number;
                if(idx - 1 >= 0)
                    marked[idx - 1] = true;
                if(idx + 1 < n)
                    marked[idx + 1] = true;
            }
        }
        
        return score;
    }
};