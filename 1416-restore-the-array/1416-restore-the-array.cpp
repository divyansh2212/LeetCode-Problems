class Solution {
    const int mod = 1e9 + 7;
    
    unordered_map<int, unordered_map<int, int>> mp;
    
    int solve(int idx, string &s, int last, int &k)
    {
        int n = s.length();
        if(idx == n)
        {
            if(last >= 1 && last <= k)
                return 1;
            return 0;
        }  
        
        if(mp.find(idx) != mp.end() && mp[idx].find(last) != mp[idx].end())
            return mp[idx][last];
        
        int way1 = 0, way2 = 0;
        
        long number = last * 10L + s[idx] - '0';
        if(number >= 1 && number <= k)
        {
            way1 = solve(idx + 1, s, number, k);
            way2 = solve(idx + 1, s, 0, k);
        }
        
        return mp[idx][last] = (way1 + 0L + way2) % mod;
    }
    
public:
    int numberOfArrays(string s, int k) {
        int n = s.length();
        mp.clear();
        return solve(0, s, 0, k);
    }
};