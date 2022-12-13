class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int n = dictionary.size();
        
        string ans = "";
        for(int it = 0; it < n; it++)
        {
            string str = dictionary[it];
            if(s.length() < str.length() || ans.length() > str.length())
                continue;
            int i = 0, j = 0;
            while(i < s.length() && j < str.length())
            {
                if(s[i] == str[j])
                    i++, j++;
                else
                    i++;
            }
            if(j == str.length())
            {
                if(ans.length() < str.length())
                    ans = str;
                else if(ans.length() == str.length())
                    ans = min(ans, str);
            }
        }
        return ans;
    }
};