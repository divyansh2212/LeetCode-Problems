class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        int n = words.size();
        
        map<char, int> orderNum;
        
        for(int i = 0; i < 26; i++)
            orderNum[order[i]] = i;
        
        for(int i = 1; i < n; i++)
        {
            int sameCnt = 0;
            for(int j = 0; j < min(words[i].length(), words[i - 1].length()); j++)
            {
                if(words[i - 1][j] == words[i][j])
                {
                    sameCnt++;
                    continue;
                }

                else if(orderNum[words[i - 1][j]] > orderNum[words[i][j]])
                    return false;
                else
                    break;
            }
            
            if(sameCnt == min(words[i].length(), words[i - 1].length()))
            {
                if(words[i - 1].length() > words[i].length())
                    return false;
            }
        }
        
        return true;
    }
};