class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        string curr = "";
        for(int i = 0; i < n / 2; i++) {
            curr += s[i];
            if(n % (curr.length()) == 0) {
                string copy = curr;
                while(copy.length() < n) {
                    copy += curr;
                }
                if(copy == s)
                    return true;
            }
        }
        
        return false;
    }
};