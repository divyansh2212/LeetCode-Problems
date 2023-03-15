
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        bool foundNull = false;
        while(!q.empty())
        {
            auto top = q.front();
            q.pop();
            if(top == NULL)
                foundNull = true;
            else
            {
                if(foundNull)
                    return false;
                q.push(top->left);
                q.push(top->right);
            }
        }
        
        return true;
    }
};