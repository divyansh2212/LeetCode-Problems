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
    void traversal(vector<int> &arr, TreeNode* root)
    {
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL)
        {
            arr.push_back(root->val);
            return;
        }
        traversal(arr, root->left);
        traversal(arr, root->right);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1, arr2;
        traversal(arr1, root1);
        traversal(arr2, root2);
        return arr1 == arr2;
    }
};