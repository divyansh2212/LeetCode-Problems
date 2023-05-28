class Node{
  
    Node* links[26];
    bool flag = false;
    
    public:
    
    bool contains(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    
    void put (char ch, Node* node)
    {
        links[ch - 'a'] = node;
    }
    
    Node* next(char ch)
    {
        return links[ch - 'a'];
    }
    
    void setEnd()
    {
        flag = true;
    }
    
    bool isEnd()
    {
        return flag;
    }
    
};

class Trie {
    
    Node* root;
    
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        
        int n = word.length();
        Node* temp = root;
        
        for(int i = 0; i < n; i++) 
        {
            char ch = word[i];
            
            if(temp->contains(ch) == false)
                temp->put(ch, new Node());
            
            temp = temp->next(ch);
        }
        
        temp->setEnd();
    }
    
    bool search(string word) {
        
        int n = word.length();
        Node* temp = root;
        
        for(int i = 0; i < n; i++)
        {
            char ch = word[i];
            
            if(temp->contains(ch) == false)
                return false;
            
            temp = temp->next(ch);
        }
        
        if(temp->isEnd() == true)
            return true;
        else
            return false;
    }
    
    bool startsWith(string prefix) 
    {
        int n = prefix.length();
        
        Node* node = root;
        
        for(int i = 0; i < n; i++)
        {
            char ch = prefix[i];
            if(node->contains(ch) == false)
                return false;
            
            node = node->next(ch);
        }
        
        return true;
    }
};