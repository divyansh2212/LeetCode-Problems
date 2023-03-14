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
    
    void traversal(TreeNode* root, int &sum, int num)
    {
        num = (num * 10) + root->val;
        if(root->left == NULL && root->right == NULL)
        {
            sum += num;
            return;
        }
        if(root->left)
            traversal(root->left, sum, num);
        if(root->right)
            traversal(root->right, sum, num);
    }
    
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        traversal(root, sum, 0);
        return sum;
    }
};