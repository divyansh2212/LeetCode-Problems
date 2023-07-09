class Solution {
public:
    int largestVariance(string s) {
        int n = s.length();
        int ans = 0;
        vector<int> hsh(26, 0);
        for(auto &ch : s) {
            hsh[ch - 'a']++;
        }
        
        for(char ch1 = 'a'; ch1 <= 'z'; ch1++) {
            for(char ch2 = 'a'; ch2 <= 'z'; ch2++) {
                
                if(hsh[ch1 - 'a'] == 0 || hsh[ch2 - 'a'] == 0 || ch1 == ch2)
                    continue;
                
                int count1 = 0, count2 = 0;
                
                for(auto &ch : s) {
                    if(ch == ch1) {
                        count1++;
                    }
                    else if(ch == ch2) {
                        count2++;
                    }
                    if(count2 > count1) {
                        count2 = 0;
                        count1 = 0;
                    }
                    
                    else if(count2 > 0 && count1 > 0)
                        ans = max(ans, count1 - count2);
                }
            }
        }
        
        reverse(s.begin(), s.end());
        
        for(char ch1 = 'a'; ch1 <= 'z'; ch1++) {
            for(char ch2 = 'a'; ch2 <= 'z'; ch2++) {
                
                if(hsh[ch1 - 'a'] == 0 || hsh[ch2 - 'a'] == 0 || ch1 == ch2)
                    continue;
                
                int count1 = 0, count2 = 0;
                
                for(auto &ch : s) {
                    if(ch == ch1) {
                        count1++;
                    }
                    else if(ch == ch2) {
                        count2++;
                    }
                    if(count2 > count1) {
                        count2 = 0;
                        count1 = 0;
                    }
                    
                    else if(count2 > 0 && count1 > 0)
                        ans = max(ans, count1 - count2);
                }
            }
        }
        
        return ans;
    }
};