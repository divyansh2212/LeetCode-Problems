class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        intervals.push_back(newInterval);
        
        sort(intervals.begin(), intervals.end());
        
        int n = intervals.size();
        
        vector<vector<int>> ans;
        
        int prevEnd = intervals[0][1], prevStart = intervals[0][0];
        for(int i = 1; i < n; i++)
        {
            if(prevEnd < intervals[i][0])
            {
                ans.push_back({prevStart, prevEnd});
                prevStart = intervals[i][0], prevEnd = intervals[i][1];
            }
            else
                prevEnd = max(prevEnd, intervals[i][1]);
        }
        ans.push_back({prevStart, prevEnd});
        
        return ans;
    }
};