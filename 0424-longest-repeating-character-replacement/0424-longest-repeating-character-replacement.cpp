class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.length();
        
        int ans = 1;
        
        for(char ch = 'A'; ch <= 'Z'; ch++)
        {
            int available = k;
            int i = 0, j = 0;
            
            while(j < n)
            {
                if(s[j] != ch) {
                    available--;
                }
                while(available < 0) {
                    if(s[i] != ch) {
                        available++;
                    }
                    i++;
                }
                ans = max(ans, j - i + 1);
                j++;
            }
        }
        
        return ans;
    }
};