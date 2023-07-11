/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*, TreeNode*> parentMap;
        queue<TreeNode*> q;
        q.push(root);
        parentMap[root] = NULL;
        
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            if(front->left) {
                parentMap[front->left] = front;
                q.push(front->left);
            }
            if(front->right) {
                parentMap[front->right] = front;
                q.push(front->right);
            }
        }
        
        vector<int> visited(501, false);
        
        q.push(target);
        visited[target->val] = true;
        int level = 0;
        vector<int> ans;
        
        while(!q.empty() && level < k + 1)
        {
            int sz = q.size();
            for(int i = 0; i < sz; i++) 
            {
                auto node = q.front();
                q.pop();
                if(level == k ) {
                    ans.push_back(node->val);
                }
                if(node->left && visited[node->left->val] == false) {
                    q.push(node->left);
                    visited[node->left->val] = true;
                }
                if(node->right && visited[node->right->val] == false) {
                    q.push(node->right);
                    visited[node->right->val] = true;
                }
                if(parentMap[node] && visited[parentMap[node]->val] == false) {
                    q.push(parentMap[node]);
                    visited[parentMap[node]->val] = true;
                }
            }
            level++;
        }
        
        return ans;
    }
}; 