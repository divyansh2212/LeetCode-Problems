class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        for(int i = 1; i <= n; i++)
        {
            int count1 = 0, count2 = 0;
            
            for(int j = 0; j < trust.size(); j++)
            {
                if(trust[j][1] == i)
                    count2++;
                if(trust[j][0] == i)
                    count1++;
            }
            
            if(count1 == 0 && count2 == n - 1)
                return i;
        }
            
        return -1;
    }
};