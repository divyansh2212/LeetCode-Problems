class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> hsh;
        int i = 0, j = 0;
        int ans = 0;
        
        while(j < n)
        {
            hsh[s[j]]++;
            while(hsh[s[j]] > 1) {
                hsh[s[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        
        return ans;
    }
};