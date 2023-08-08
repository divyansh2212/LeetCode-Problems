class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if(k > n)
            return false;
        unordered_map<char, int> hash;
        for(int i = 0; i < n; i++) {
            hash[s[i]]++;
        }
        int odds = 0;
        for(auto &it : hash) {
            if(it.second % 2)
                odds++;
        }
        
        return odds <= k;
    }
};