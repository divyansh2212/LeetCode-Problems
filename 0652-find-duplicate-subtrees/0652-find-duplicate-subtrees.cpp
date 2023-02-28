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
    
    unordered_map<string, int> hashMap;
    string solve(TreeNode* root, vector<TreeNode*> &ans)
    {
        if(root == NULL)
            return "#";
        string s = solve(root->left, ans) + "," + solve(root->right, ans) + "," + to_string(root->val);
        hashMap[s]++;
        if(hashMap[s] == 2)
            ans.push_back(root);
        return s;
    }
    
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        solve(root, ans);
        return ans;
    }
};