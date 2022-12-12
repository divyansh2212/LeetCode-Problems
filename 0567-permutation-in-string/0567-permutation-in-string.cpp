class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length() < s1.length()) return false;
        
        sort(s1.begin(), s1.end());
        
        for(int i = 0; i < s2.length(); i++)
        {
            if(s2.length() - i + 1 < s1.length())
                break;
            string subst = s2.substr(i, s1.length());
            sort(subst.begin(), subst.end());
            if(subst == s1)
                return true;
        }
        return false;
    }
};