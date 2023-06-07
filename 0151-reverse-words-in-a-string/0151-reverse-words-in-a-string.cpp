class Solution {

    string trim(string &s)
    {
        string modified = "";
        int i = 0;
        while(i < s.length() && s[i] == ' ')
            i++;
        while(i < s.length())
        {
            modified.push_back(s[i]);
            i++;
        }
        while(modified.size() && modified.back() == ' ')
            modified.pop_back();
        return modified;
    }
    
    public:
    string reverseWords(string s) {
        
        string trimmed = trim(s);
        string ans = "";
        vector<string> words;
        
        int i = 0;
        int n = trimmed.length();
        
        while(i < n)
        {
            int initial = i;
            string word = "";
            while(i < n && trimmed[i] != ' ')
            {
                word.push_back(trimmed[i]);
                i++;
            }
    
            if(initial == i)
                i++;
            
            else
            words.push_back(word);
        }
        
        for(int i = words.size() - 1; i >= 0; i--)
        {
            ans += words[i];
            if(i != 0)
            ans.push_back(' ');
        }
        
        return ans;
    }
};