
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        TreeNode* node = root;
        stack<TreeNode*> st;
        
        while(1)
        {
            if(node) {
                st.push(node);
                node = node->left;
            }
            
            else {
                if(st.empty())
                    break;
                ans.push_back(st.top()->val);
                node = st.top()->right;
                st.pop();
            }
        }
        
        return ans;
    }
};