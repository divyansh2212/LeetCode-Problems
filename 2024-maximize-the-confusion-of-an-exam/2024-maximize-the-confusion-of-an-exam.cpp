class Solution {
public:
    int maxConsecutiveAnswers(string key, int k) {
        int n = key.length();
        
        int ans = 1;
        int i = 0, j = 0;
        
        // checking for trues
        int possible = k;
        while(j < n)
        {
            if(key[j] == 'F')
            {
                if(possible > 0) 
                    possible--;
                else 
                {
                    while(possible == 0) 
                    {
                        if(key[i] == 'F') 
                            possible++;
                        i++;
                    }
                    possible = 0;
                }
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        
        i = 0, j = 0;
        possible = k;
        while(j < n)
        {
            if(key[j] == 'T')
            {
                if(possible > 0) 
                    possible--;
                else 
                {
                    while(possible == 0) 
                    {
                        if(key[i] == 'T') 
                            possible++;
                        i++;
                    }
                    possible = 0;
                }
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        
        
        return ans;
    }
};