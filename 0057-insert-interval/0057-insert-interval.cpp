class Solution {
    
    // bool static comparator(vector<int> &a, vector<int> &b)
    // {
    //     return a[0] < b[0];
    // }
    
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int n = intervals.size();
        
        vector<vector<int>> ans;
        int x = newInterval[0], y = newInterval[1];
        
        for(int i = 0; i < n; i++) {
            if((x >= intervals[i][0] && intervals[i][1] >= x) || (intervals[i][0] >= x && y >= intervals[i][0])) {
                x = min(x, intervals[i][0]);
                y = max(y, intervals[i][1]);
            }
            else {
                ans.push_back(intervals[i]);
            }
        }
        ans.push_back({x, y});
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};