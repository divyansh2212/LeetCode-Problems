class Node{
 
    private:
    public:
    int key;
    int value;
    Node* prev = NULL;
    Node* next = NULL;
    
    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
    }
};

class LRUCache {
    
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> address;
    int capacity;
    
    void deleteNode(Node* node)
    {
        address.erase(node->key);
        Node* nodenext = node->next;
        Node* nodeprev = node->prev;
        nodeprev->next = nodenext;
        nodenext->prev = nodeprev;
        delete node;
    }
    
    void addNode(int key, int value)
    {
        Node* newNode = new Node(key, value);
        Node* temp = head->next;
        newNode->next = temp;
        temp->prev = newNode;
        head->next = newNode;
        newNode->prev = head;
        address[key] = newNode;
    }
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        address.clear();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(address.find(key) != address.end()) {
            Node* nodeaddress = address[key];
            int val = nodeaddress->value;
            deleteNode(nodeaddress);
            address.erase(key);
            addNode(key, val);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(address.find(key) != address.end()) {
            Node* nodeaddress = address[key];
            deleteNode(nodeaddress);
            addNode(key, value);
        }
        else if(address.size() < capacity) {
            addNode(key, value);
        }
        else {
            deleteNode(tail->prev);
            addNode(key, value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */