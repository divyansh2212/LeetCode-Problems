class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        vector<int> hsh1(26, 0);
        vector<int> hsh2(26, 0);
        
        for(int i = 0; i < s1.length(); i++)
            hsh1[s1[i] - 'a']++;
        
        if(s2.length() < s1.length())
            return false;
        
        
        int i = 0, j = 0;
        
        for(j = 0; j < s1.length(); j++)
            hsh2[s2[j] - 'a']++;
        
        if(hsh1 == hsh2)
            return true;
        
        while(j < s2.length())
        {
            hsh2[s2[j] - 'a']++;
            hsh2[s2[i] - 'a']--;
            
            if(hsh1 == hsh2)
                return true;
            
            i++, j++;
        }
        
        return false;
    }
};