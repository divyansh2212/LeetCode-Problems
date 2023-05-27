class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        set<string> list(wordList.begin(), wordList.end());
        
        queue<string> q;
        int steps = 0;
        q.push(beginWord);
        list.erase(beginWord);
        
        while(!q.empty())
        {
            steps++;
            int size = q.size();
            
            for(int i = 0; i < size; i++)
            {
                string top = q.front(); q.pop();
                if(top == endWord)
                    return steps;
                
                for(int j = 0; j < top.length(); j++)
                {
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        if(top[j] == ch)
                            continue;
                        string str = top;
                        str[j] = ch;
                        if(list.find(str) != list.end()) {
                            q.push(str);
                            list.erase(str);
                        }
                    }
                }
            }
        }
        
        return 0;
    }
};