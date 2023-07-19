class Solution {
    
    bool static comparator(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), comparator);
        
        int end = -1e5;
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(intervals[i][0] >= end) {
                end = intervals[i][1];
            }
            else {
                ans++;
            }
        }
        
        return ans;
    }
};