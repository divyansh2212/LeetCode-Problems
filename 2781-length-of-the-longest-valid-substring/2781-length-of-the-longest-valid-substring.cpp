class Solution {
    
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        int n = word.length();
        int ans = 0;
        unordered_set<string> st;
        
        for(int i = 0; i < forbidden.size(); i++) {
            reverse(forbidden[i].begin(), forbidden[i].end());
            st.insert(forbidden[i]);
        }
        
        int i = 0, j = 0;
        while(j < n) {  
            string str = "";
            for(int k = j; k >= i; k--) {
                str.push_back(word[k]);
                if(st.find(str) != st.end()) {
                    i = k + 1;
                    break;
                }
                else {
                    int len = str.length();
                    if(len > 10) {
                        ans = max(ans, j - i + 1);
                        break;
                    }
                    else {
                        ans = max(ans, len);
                    }
                }
            }
            j++;
        }
        
        
        return ans;
    }
};