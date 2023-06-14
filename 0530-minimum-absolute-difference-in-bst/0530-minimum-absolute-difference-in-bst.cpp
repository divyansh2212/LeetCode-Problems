class Solution
{
    void traversal(TreeNode *root, int &ans, TreeNode *&prev)
    {
        if (root->left)
            traversal(root->left, ans, prev);
        if (prev)
            ans = min(ans, abs(prev->val - root->val));
        prev = root;
        if (root->right)
            traversal(root->right, ans, prev);
    }

public:
    int getMinimumDifference(TreeNode *root)
    {
        int ans = 1e9;
        TreeNode *prev = NULL;
        traversal(root, ans, prev);
        return ans;
    }
};