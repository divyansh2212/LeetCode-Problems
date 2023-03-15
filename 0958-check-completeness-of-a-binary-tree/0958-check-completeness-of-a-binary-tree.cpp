
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        int level = 0;
        bool complete = true;
        while(!q.empty())
        {
            if(complete == false)
                return false;
            int size = q.size();
            if(size != pow(2, level))
                complete = false;
            
            int missing = 0;
            for(int i = 0; i < size; i++)
            {
                auto front = q.front(); q.pop();
                if(front->left)
                {
                    if(missing)
                        return false;
                    q.push(front->left);
                }   
                else
                    missing++;
                if(front->right)
                {
                    if(missing)
                        return false;
                    q.push(front->right);
                }
                else
                    missing++;
            }   
            
            level++;
        }
        
        return true;
    }
};