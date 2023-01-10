class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int ans = max(1, k);
        
        vector<int> hsh(26, 0);
        
        int i = 0, j = 0;
        
        while(j < n)
        {
            hsh[s[j] - 'A']++;
            
            int mx = 0, total = 0;
            for(int k = 0; k < 26; k++)
            {
                if(hsh[k] == 0)
                    continue;
                mx = max(mx, hsh[k]);
                total += hsh[k];
            }
            
            if(total - mx <= k)
            {
                ans = max(ans, j - i + 1);
            }
            else
            {
                hsh[s[i] - 'A']--;
                i++;
            }
            j++;
        }
        
        return ans;
    }
};