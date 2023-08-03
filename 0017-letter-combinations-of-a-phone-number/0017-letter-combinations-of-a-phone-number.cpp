class Solution {
    
    void generate(int idx, string &digits, string &curr, vector<string> &ans, unordered_map<char, string> &dials)
    {
        int n = digits.length();
        if(idx == n) {
            if(curr != "")
            ans.push_back(curr);
            return;
        }
        
        for(auto &it : dials[digits[idx]]) {
            curr.push_back(it);
            generate(idx + 1, digits, curr, ans, dials);
            curr.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> dials;
        dials['2'] = "abc";
        dials['3'] = "def";
        dials['4'] = "ghi";
        dials['5'] = "jkl";
        dials['6'] = "mno";
        dials['7'] = "pqrs";
        dials['8'] = "tuv";
        dials['9'] = "wxyz";
        
        vector<string> ans;
        string curr = "";
        generate(0, digits, curr, ans, dials);
        return ans;
    }
};