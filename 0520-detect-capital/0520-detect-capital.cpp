class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        
        int lowercase = 0, uppercase = 0;
        for(int i = 0; i < n; i++)
        {
            if(word[i] >= 'a' && word[i] <= 'z')
                lowercase++;
            else
                uppercase++;
        }
        
        if(uppercase == n)
            return true;
        else if(lowercase == n)
            return true;
        else if(uppercase == 1 && word[0] >= 'A' && word[0] <= 'Z')
            return true;
        else
            return false;
    }
};