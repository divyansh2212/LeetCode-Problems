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
    void solve(TreeNode* root, int minSoFar, int maxSoFar, int &maxDiff)
    {
        if(root == NULL)
            return;
        maxDiff = max(maxDiff, abs(minSoFar - root->val));
        maxDiff = max(maxDiff, abs(maxSoFar - root->val));
        minSoFar = min(minSoFar, root->val);
        maxSoFar = max(maxSoFar, root->val);
        solve(root->left, minSoFar, maxSoFar, maxDiff);
        solve(root->right, minSoFar, maxSoFar, maxDiff);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        solve(root, root->val, root->val, ans);
        return ans;
    }
};