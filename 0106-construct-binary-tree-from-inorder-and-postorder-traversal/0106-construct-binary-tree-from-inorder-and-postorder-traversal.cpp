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
    
    TreeNode* build(int postStart, int postEnd, int inStart, int inEnd, vector<int>& inorder, vector<int>& postorder, map<int, int> &inMap)
    {
        if(inStart > inEnd || postStart > postEnd)
            return NULL;
        
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int idx = inMap[postorder[postEnd]];
        int leftElements = idx - inStart;
        
        root->left = build(postStart, postStart + leftElements - 1, inStart, idx - 1, inorder, postorder, inMap);
        root->right = build(postStart + leftElements, postEnd - 1, idx + 1, inEnd, inorder, postorder, inMap);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        map<int, int> inMap;
        for(int i = 0; i < n; i++)
            inMap[inorder[i]] = i;
        
        return build(0, n - 1, 0, n - 1, inorder, postorder, inMap);
    }
};