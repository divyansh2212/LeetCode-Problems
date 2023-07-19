class Solution {
    
    // bool static comparator(vector<int> &a, vector<int> &b)
    // {
    //     return a[0] < b[0];
    // }
    
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        intervals.push_back(newInterval);
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        int start = intervals[0][0];
        int end = intervals[0][1];
        
        for(int i = 0; i < n; i++) {
            if((end >= intervals[i][0] && end <= intervals[i][1]) || (intervals[i][0] >= start && intervals[i][0] <= end)) {
                start = min(intervals[i][0], start);
                end = max(end, intervals[i][1]); 
            }
            else {
                ans.push_back({start, end});
                start = intervals[i][0], end = intervals[i][1];
            }
        }
        ans.push_back({start, end});
        
        return ans;
    }
};