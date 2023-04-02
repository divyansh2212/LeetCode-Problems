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
    
    int solve(TreeNode* root, TreeNode* parent, TreeNode* grandparent)
    {
        if(root == NULL)
            return 0;
        int currSum = 0;
        if(grandparent != NULL && (grandparent->val) % 2 == 0)
            currSum += root->val;
        currSum += solve(root->left, root, parent);
        currSum += solve(root->right, root, parent);
        
        return currSum;
    }
    
public:
    int sumEvenGrandparent(TreeNode* root) {
        // int sum = 0;
        return solve(root, NULL, NULL);
    }
};