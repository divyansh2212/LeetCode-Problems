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
public:
    int maxLevelSum(TreeNode* root) {
        
        int ans = 1;
        int level = 1;
        int maxSum = INT_MIN;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int levelSum = 0;
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                auto front = q.front(); q.pop();
                levelSum += front->val;
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            if(levelSum > maxSum)
                maxSum = levelSum, ans = level;
            level++;
        }
        
        return ans;
    }
};