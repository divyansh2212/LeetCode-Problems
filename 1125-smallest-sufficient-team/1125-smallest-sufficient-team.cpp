class Solution {
    
    int solve(int &reqd_mask, vector<int> &person, int idx, int mask, vector<vector<int>> &dp, vector<vector<int>> &choice)
    {
        int n = person.size();
        if(mask == reqd_mask)
            return 0;
        if(idx == n) {
            return 100000;
        }
        if(dp[idx][mask] != -1)
            return dp[idx][mask];
        
        int way1 = 1 + solve(reqd_mask, person, idx + 1, (mask | person[idx]), dp, choice);
        int way2 = solve(reqd_mask, person, idx + 1, mask, dp, choice);
        
        if(way1 < way2) {
            choice[idx][mask] = 1;
        }
        
        return dp[idx][mask] = min(way1, way2);
    }
    
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        unordered_map<string, int> skillbit;
        int reqd_mask = 0;
        for(int i = 0; i < n; i++) {
            skillbit[req_skills[i]] = i;
            reqd_mask |= (1 << i);
        }
        
        n = people.size();
        vector<int> person(n, 0);
        for(int i = 0; i < n; i++) {
            int curr = 0;
            for(auto &it : people[i]) {
                curr |= (1 << skillbit[it]);
            }
            person[i] = curr;
        }
        
        vector<vector<int>> dp(n, vector<int> ((1<<16), -1));
        vector<vector<int>> choice(n, vector<int> ((1<<16), 0));
        int peopleset = solve(reqd_mask, person, 0, 0, dp, choice);
        
        vector<int> ans;
        int mask = 0;
        for(int i = 0; i < n; i++) {
            if(choice[i][mask]) {
                ans.push_back(i);
                mask |= person[i];
            }
            if(mask == reqd_mask)
                break;
        }
        
        return ans;
    }
};