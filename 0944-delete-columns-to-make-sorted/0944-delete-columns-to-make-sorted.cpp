class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].length(), ans = 0;
        
        for(int j = 0; j < m; j++)
        {
            char prev = strs[0][j];
            for(int i = 1; i < n; i++)
            {
                if(prev > strs[i][j])
                {
                    ans++;
                    break;
                }
                else
                    prev = strs[i][j];
            }
        }
        
        return ans;
    }
};