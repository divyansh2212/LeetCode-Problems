class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n = s1.length();
        int m = s2.length();
        vector<int> hsh1(26, 0);
        vector<int> hsh2(26, 0);
        
        for(int i = 0; i < n; i++) {
            hsh1[s1[i] - 'a']++;
        }
        
        int i = 0, j = 0;
        
        while(j < m)
        {
            hsh2[s2[j] - 'a']++;
            while(hsh2[s2[j] - 'a'] > hsh1[s2[j] - 'a']) {
                hsh2[s2[i] - 'a']--;
                i++;
            }
            if(j - i + 1 == n) {
                return true;
            }
            j++;
        }
        
        return false;
    }
};