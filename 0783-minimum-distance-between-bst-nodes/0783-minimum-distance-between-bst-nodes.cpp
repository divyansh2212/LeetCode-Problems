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
    
    void dfs(TreeNode* root, vector<int> &nodes)
    {
        if(root == NULL)
            return;
    
        dfs(root->left, nodes);
        nodes.push_back(root->val);
        dfs(root->right, nodes);
    }
    
public:
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;
        vector<int> nodes;
        dfs(root, nodes);
        
        for(int i = 1; i < nodes.size(); i++)
            ans = min(ans, nodes[i] - nodes[i - 1]);
        
        return ans;
    }
};