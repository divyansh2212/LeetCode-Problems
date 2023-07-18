class Solution {
    
    bool check(unordered_map<char, int> &hashS, unordered_map<char, int> &hashT)
    {
        for(auto &it : hashT)
        {
            if(hashS[it.first] < it.second)
                return false;
        }
        return true;
    }
    
public:
    string minWindow(string s, string t) {
        
        int n = s.length(), m = t.length();
        int start = -1, end = 1e6;
        
        unordered_map<char, int> hashT;
        unordered_map<char, int> hashS;
        for(int i = 0; i < m; i++) {
            hashT[t[i]]++;
        }
        
        int i = 0, j = 0;
        
        while(j < n)
        {
            hashS[s[j]]++;

            while(check(hashS, hashT)) 
            {
                if(end - start > j - i)
                    start = i, end = j;
                hashS[s[i]]--;
                i++;
            }
            j++;
        }
        
        if(end == 1e6){
            return "";
        }
        
        return s.substr(start, end - start + 1);
    }
};