class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length() < s1.length()) return false;
        
        int n = s1.length(), m = s2.length();
        
        vector<int> hsh1(26, 0);
        for(int i = 0; i < n; i++)
            hsh1[s1[i] - 'a']++;
        
        int i = 0, j = 0;
        vector<int> hsh2(26, 0);
        
        while(j < m)
        {
            hsh2[s2[j] - 'a']++;
            if(j - i + 1 < n)
            {
                j++;
                continue;
            }
            
            if(hsh1 == hsh2)
                return true;
            hsh2[s2[i] - 'a']--;
            i++, j++;
        }
        
        return false;
    }
};