class Solution {
    
    bool check(vector<int>& dist, double &hour, int &speed)
    {
        int n = dist.size();
        double mark = 0;
        
        for(int i = 0; i < n; i++)
        {
            mark += ((dist[i]*1.0) / speed);
            if(i != n - 1)
                mark = ceil(mark);
        }
        
        return (hour >= mark);
    }
    
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        int lo = 0, hi = 1e7, ans = -1;
        
        while(lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if(check(dist, hour, mid)) {
                ans = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};