class Solution {

    void generate(int open, int close, vector<string> &ans, string &curr, int &n)
    {
        if(open == n && close == n) {
            ans.push_back(curr);
            return;
        }
        
        if(open > close) {
            curr.push_back(')');
            generate(open, close + 1, ans, curr, n);
            curr.pop_back();
        }
        if(open < n) {
            curr.push_back('(');
            generate(open + 1, close, ans, curr, n);
            curr.pop_back();
        }
    }
    
    public:
    vector<string> generateParenthesis(int n) {
        int open = 0, close = 0;
        vector<string> ans;
        string curr = "";
        generate(open, close, ans, curr, n);
        return ans;
    }
};