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
    void traversal(TreeNode* root, int &low, int &high, int &reqdSum)
    {
        if(root == NULL)
            return;
        if(root->val <= high && root->val >= low)
        {
            reqdSum += root->val;
            traversal(root->left, low, high, reqdSum);
            traversal(root->right, low, high, reqdSum);
        }
        
        else if(root->val > high)
            traversal(root->left, low, high, reqdSum);
        else
            traversal(root->right, low, high, reqdSum);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int reqdSum = 0;
        traversal(root, low, high, reqdSum);
        return reqdSum;
    }
};