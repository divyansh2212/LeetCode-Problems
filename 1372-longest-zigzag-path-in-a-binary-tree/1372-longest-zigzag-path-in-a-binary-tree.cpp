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
    int ans = 0;
    
    // left = -1, right = 1
    
    void traversal(TreeNode* root, int curr, int last)
    {
        ans = max(ans, curr);
        
        if(root == NULL)
            return;
        
        if(last == -1)
        {
            if(root->right)
            {
                curr++;
                traversal(root->right, curr, 1);
                curr--;    
            }
            curr = 1;
            if(root->left)
                traversal(root->left, curr, -1);
        }
        
        else if(last == 1)
        {
            if(root->left)
            {
                curr++;
                traversal(root->left, curr, -1);
                curr--;    
            }
            curr = 1;
            if(root->right)
                traversal(root->right, curr, 1);
        }
        
        else
        {
            curr = 1;
            if(root->right)
                traversal(root->right, curr, 1);
            if(root->left)
                traversal(root->left, curr, -1);
        }
        
    }
    
public:
    int longestZigZag(TreeNode* root) {
        traversal(root, 0, 0);
        return ans;
    }
};