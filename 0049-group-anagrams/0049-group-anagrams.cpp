class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        int n = strs.size();
        map<vector<int>, vector<int>> mp;
        
        for(int i = 0; i < n; i++)
        {
            vector<int> hsh(26, 0);
            for(int j = 0; j < strs[i].length(); j++) {
                hsh[strs[i][j] - 'a']++;
            }
            mp[hsh].push_back(i);
        }
        
        for(auto &it : mp)
        {
            vector<string> curr;
            for(auto &idx : it.second) {
                curr.push_back(strs[idx]);        
            }
            ans.push_back(curr);
        }
        
        return ans;
    }
};