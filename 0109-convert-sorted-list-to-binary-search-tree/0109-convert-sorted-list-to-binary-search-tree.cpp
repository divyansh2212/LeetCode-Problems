/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    void traversal(ListNode* head, vector<int> &nodes)
    {
        ListNode* temp = head;
        while(temp)
        {
            nodes.push_back(temp->val);
            temp = temp->next;
        }
    }
    
    TreeNode* buildTree(int start, int end, vector<int> &nodes)
    {
        if(start > end)
            return NULL;
        int idx = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nodes[idx]);
        
        root->left = buildTree(start, idx - 1, nodes);
        root->right = buildTree(idx + 1, end, nodes);
        
        return root;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nodes;
        traversal(head, nodes);
        sort(nodes.begin(), nodes.end());
        
        return buildTree(0, nodes.size() - 1, nodes);
    }
};