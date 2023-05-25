class Solution {
    
    bool fulfilled(map<char, int> &mp)
    {
        for(auto &it : mp)
            if(it.second > 0)
                return false;
        
        return true;
    }
    
public:
    int balancedString(string s) {
        
        int N = s.length();
        int required = N/4;
        map<char, int> freq;
        int ans = 1e9;
        
        for(int i = 0; i < N; i++)
            freq[s[i]]++;
                
        bool equal = true;
        for(auto &it : freq) {
            if(it.second != required) equal = false;
            it.second = max(0, it.second - required);
        }
        
        if(equal) return 0;
        
        int j = 0;
        for(int i = 0; i < N; i++)
        {
            freq[s[i]]--;
            
            while(fulfilled(freq))
            {
                ans = min(ans, i - j + 1);
                freq[s[j]]++;
                j++;
            }
        }
        
        return ans;
    }
};