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
    const int mod = 1e9 + 7;
    int evaluate(TreeNode* root, unordered_map<int, int> &mp)
    {
        if(root == NULL)
            return 0;
        int lt = evaluate(root->left, mp);
        int rt = evaluate(root->right, mp);
        mp[lt]++, mp[rt]++;
        
        return root->val + lt + rt;
    }
public:
    int maxProduct(TreeNode* root) {
        unordered_map<int, int> mp;
        int totalSum = evaluate(root, mp);
        
        long long maxProduct = 1;
        
        for(auto &it : mp)
        {
            long long firstTree = it.first, secondTree = totalSum - it.first;
            maxProduct = max(maxProduct, (firstTree * secondTree));
        }
        
        return maxProduct % mod;
    }
};