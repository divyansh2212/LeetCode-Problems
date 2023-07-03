class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length())
            return false;
        
        int n = s.length();
        vector<int> indices[26];
        
        bool flag = false;
        for(int i = 0; i < n; i++) {
            indices[s[i] - 'a'].push_back(i);
            if(indices[s[i] - 'a'].size() > 1)
                flag = true;
        }
        
        if(s==goal && flag)
            return true;
        
        for(int i = 0; i < 26; i++) {
            for(int j = i + 1; j < 26; j++) {
                for(auto &it : indices[i]) {
                    for(auto &it2 : indices[j]) {
                        swap(s[it], s[it2]);
                        if(s == goal)
                            return true;
                        swap(s[it], s[it2]);
                    }
                }
            }
        }
        
        return false;
    }
};