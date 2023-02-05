class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int n = s.length(), m = p.length();
        vector<int> ans;
        
        if(m > n)
            return {};
        
        vector<int> hshp(26, 0);
        vector<int> hshs(26, 0);
        for(int i = 0; i < m; i++)
            hshp[p[i] - 'a']++;
        
        int i = 0, j = 0;
        
        while(j < n)
        {
            hshs[s[j] - 'a']++;
            if(j - i + 1 == m)
            {
                if(hshs == hshp)
                    ans.push_back(i);
                hshs[s[i] - 'a']--;
                i++;
            }
            j++;
        }
        
        return ans;
    }
};