class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        
        vector<vector<int>> ans;
        
        int start = intervals[0][0], finish = intervals[0][1];
        for(int i = 1; i < n; i++)
        {
            if(intervals[i][0] >= start && intervals[i][0] <= finish)
                finish = max(finish, intervals[i][1]);
            else
            {
                ans.push_back({start, finish});
                start = intervals[i][0], finish = intervals[i][1];
            }
        }
    
        ans.push_back({start, finish});
        
        return ans;
    }
};