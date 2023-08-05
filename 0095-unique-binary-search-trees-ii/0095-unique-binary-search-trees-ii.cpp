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

    vector<TreeNode*> generate(int start, int end, int &n)
    {
        vector<TreeNode*> ans;
        if (start > end)
            return {NULL};
        if(start == end) {
            return {new TreeNode(start)};
        }
        
        for(int i = start; i <= end; i++) 
        {
            vector<TreeNode*> lt = generate(start, i - 1, n);
            vector<TreeNode*> rt = generate(i + 1, end, n);
            
            for(auto & it : lt)
            {
                for(auto &it2 : rt)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = it;
                    root->right = it2;
                    ans.push_back(root);
                }
            }
        }
        
        return ans;
    }
    
public:
    vector<TreeNode*> generateTrees(int n) {
        
        return generate(1, n, n);
    }
};