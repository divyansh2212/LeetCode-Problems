class Solution {

    void generate(int num, int &n, vector<vector<int>> &ans, vector<int> &curr, int &k)
    {
        if(num == n + 1 || curr.size() == k)
        {
            if(curr.size() == k)
                ans.push_back(curr);
            return;
        }
        
        generate(num + 1, n, ans, curr, k);
        curr.push_back(num);
        generate(num + 1, n, ans, curr, k);
        curr.pop_back();
    }
    
    public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        generate(1, n, ans, curr, k);
        return ans;
    }
};