class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int, int> fruitsmp;
        
        int n = fruits.size(), i = 0, j = 0;
        
        int maxFruits = 0, curr = 0;
        while(j < n)
        {
            curr++;
            fruitsmp[fruits[j]]++;
            
            if(fruitsmp.size() > 2)
            {
                while(fruitsmp.size() > 2)
                {
                    fruitsmp[fruits[i]]--;
                    curr--;
                    if(fruitsmp[fruits[i]] == 0)
                        fruitsmp.erase(fruits[i]);
                    i++;
                }
            }
            
            maxFruits = max(maxFruits, curr);
            j++;
        }
        
        return maxFruits;
    }
};