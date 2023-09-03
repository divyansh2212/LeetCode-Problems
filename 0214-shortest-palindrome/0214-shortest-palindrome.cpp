class Solution {
    
    void func(string &a, vector<int> &lps)
    {
        int i = 0, j = 1;
        
        while(j < lps.size())
        {
            if(a[i] == a[j]) {
                lps[j] = i + 1;
                i++;
                j++;
            }
            else {
                if(i == 0) {
                    j++;
                }
                else {
                    i = lps[i - 1];
                }
            }
        }
    }
    
public:
    string shortestPalindrome(string s) {

        int n = s.length();
        
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        string a = s + "#" + rev;
        vector<int> lps(a.length(), 0);
        
        func(a, lps);
        int i = lps[a.length() - 1];
        
        string substr = s.substr(i);
        reverse(substr.begin(), substr.end());
        
        return substr + s;
    }
};