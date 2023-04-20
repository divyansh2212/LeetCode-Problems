
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*, long>> q;
        q.push({root, 0});
        
        unsigned long long ans = 1;
        
        while(!q.empty())
        {    
            int sz = q.size();    
            unsigned long long start = -1, end = -1;
            
            for(int i = 0; i < sz; i++)
            {
                auto top = q.front(); q.pop();
                auto node = top.first;
                unsigned long long pos = top.second;
                
                if(start == -1)
                    start = pos;
                end = pos;
                
                if(node->left)
                    q.push({node->left, 2 * pos + 1});
                if(node->right)
                    q.push({node->right, 2 * pos + 2});
            }
            
            if(start != -1)
                ans = max(ans, end - start + 1);
        }
        
        return ans;
    }
};
