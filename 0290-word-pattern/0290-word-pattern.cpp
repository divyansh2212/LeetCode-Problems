class Solution {
public:
    bool wordPattern(string pattern, string s) {
        s.push_back(' ');
        int idx = 0;
        int i = 0;
        
        map<char, string> mp;
        
        string curr = "";
        while(i < s.length())
        {
            if(s[i] == ' ')
            {
                if(idx == pattern.length())
                    return false;
                if(mp.find(pattern[idx]) != mp.end() && mp[pattern[idx]] != curr)
                        return false;
                
                mp[pattern[idx]] = curr;
                idx++;
                curr.clear();
            }
            else
                curr.push_back(s[i]);
            i++;
        }
        
        if(idx != pattern.length())
            return false;
        
        idx = 0;
        i = 0;
        
        map<string, char> mp2;
        
        curr = "";
        while(i < s.length())
        {
            if(s[i] == ' ')
            {
                if(idx == pattern.length())
                    return false;
                if(mp2.find(curr) != mp2.end() && mp2[curr] != pattern[idx])
                        return false;
                
                mp2[curr] = pattern[idx];
                idx++;
                curr.clear();
            }
            else
                curr.push_back(s[i]);
            i++;
        }
        if(idx != pattern.length())
            return false;
        
        return true;
    }
};