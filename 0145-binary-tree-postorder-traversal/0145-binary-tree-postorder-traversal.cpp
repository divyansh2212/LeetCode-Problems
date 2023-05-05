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
    
    void reverse(vector<int> &arr)
    {
        int start = 0, end = arr.size() - 1;
        while(start <= end)
        {
            swap(arr[start], arr[end]);
            start++, end--;
        }
    }
    
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty())
        {
            auto top = st.top(); st.pop();
            ans.push_back(top->val);
            
            if(top->left) st.push(top->left);
            if(top->right) st.push(top->right);
        }
        
        reverse(ans);
        
        return ans;
    }
};