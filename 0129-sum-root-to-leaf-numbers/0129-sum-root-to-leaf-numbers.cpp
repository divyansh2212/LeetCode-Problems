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
    
    void traversal(TreeNode* root, vector<int> &numbers, int num)
    {
        num = (num * 10) + root->val;
        if(root->left == NULL && root->right == NULL)
        {
            numbers.push_back(num);
            return;
        }
        if(root->left)
            traversal(root->left, numbers, num);
        if(root->right)
            traversal(root->right, numbers, num);
    }
    
public:
    int sumNumbers(TreeNode* root) {
        vector<int> numbers;
        traversal(root, numbers, 0);
        return accumulate(numbers.begin(), numbers.end(), 0);
    }
};