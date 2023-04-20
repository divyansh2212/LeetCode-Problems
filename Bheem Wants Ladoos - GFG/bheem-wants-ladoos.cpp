//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends

class Solution{
    
    Node* homeAddress;

    void travel(Node* root, Node* parent, unordered_map<Node*, Node*> &parentmp, int &home)
    {
        if(root == NULL)
            return;
        if(root->data == home)
            homeAddress = root;
        parentmp[root] = parent;
        if(root->left)
            travel(root->left, root, parentmp, home);
        if(root->right)
            travel(root->right, root, parentmp, home);
    }
    
    int dfs(Node* root, unordered_map<Node*, Node*> &parentmp, int k, unordered_set<int> &st)
    {
        if(k < 0 || root == NULL)
            return 0;
        if(st.find(root->data) != st.end())
            return 0;
        
        int ans = root->data;
        st.insert(root->data);
        
        ans += dfs(root->left, parentmp, k - 1, st) + dfs(root->right, parentmp, k - 1, st) +
                    dfs(parentmp[root], parentmp, k - 1, st);
                    
        return ans;
    }
    
    public:
    int ladoos(Node* root, int home, int k)
    {
        unordered_map<Node*, Node*> parentmp;
        travel(root, NULL, parentmp, home);
 
        unordered_set<int> st;
        return dfs(homeAddress, parentmp, k, st);
    }


};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}


// } Driver Code Ends