class Node{
  
    Node* links[26];
    bool flag = false;
    
    public:
    
    bool contains(char ch)
    {
        return links[ch - 'a'] != NULL;
    }
    
    void put(char ch, Node* node)
    {
        links[ch - 'a'] = node;
    }
    
    Node* next(char ch)
    {
        return links[ch - 'a'];
    }
    
    void markFlag()
    {
        flag = true;
    }
    
    
    bool isFlag()
    {
        return flag;
    }
    
};

class Solution {
    
    Node* root;
    
    bool isExist(string str)
    {
        Node* temp = root;
        int n = str.length();
        
        for(int i = 0; i < n; i++)
        {
            char ch = str[i];
            if(temp->contains(ch) == false)
                return false;
            temp = temp->next(ch);
        }
        
        return temp->isFlag();
    }
    
    bool isAllPrefixExists(string str)
    {
        int n = str.length();
        string temp = "";
        bool flag = true;
        for(int j = 0; j < n; j++)
        {
            char ch = str[j];
            temp.push_back(ch);
            if(isExist(temp) == false)
                return false;
        }

        return true;
    }
    
    void insertWord(string str)
    {
        int m = str.length();
            
        Node* temp = root;
        for(int j = 0; j < m; j++)
        {
            char ch = str[j];
            if(temp->contains(ch) == false)
                temp->put(ch, new Node());

            temp = temp->next(ch);
        }

        temp->markFlag();
    }
    
public:
    string longestWord(vector<string>& words) {
        
        int n = words.size();
        root = new Node();
        
        sort(words.begin(), words.end());
        
        for(int i = 0; i < n; i++)
            insertWord(words[i]);
        
        string ans = "";
        
        for(int i = 0; i < n; i++)
        {
            int m = words[i].length();
            if(m > ans.length() && isAllPrefixExists(words[i]))
                ans = words[i];
        }
        
        return ans;
    }
};