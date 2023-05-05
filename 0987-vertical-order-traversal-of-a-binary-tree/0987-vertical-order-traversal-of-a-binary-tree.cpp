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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        map<int, map<int, vector<int>>> mp;
        
        while(!q.empty())
        {
            auto top = q.front();
            q.pop();
            auto node = top.first;
            int x = top.second.first, y = top.second.second;
            
            mp[y][x].push_back(node->val);
            
            if(node->left)
                q.push({node->left, {x + 1, y - 1}});
            if(node->right)
                q.push({node->right, {x + 1, y + 1}});
        }
        
        for(auto &x : mp)
        {
            for(auto &n : x.second)
                sort(n.second.begin(), n.second.end());
        }
        
        vector<vector<int>> ans;
        for(auto &x : mp)
        {
            vector<int> curr;
            for(auto &n : x.second)
            {
                for(auto &it : n.second)
                    curr.push_back(it);
            }
            ans.push_back(curr);
        }
        
        return ans;
    }
};