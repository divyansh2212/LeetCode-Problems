class Solution {
    
    bool check(vector<int>& time, int totalTrips, long long maxTime)
    {
        long long currTrips = 0;
        for(int i = 0; i < time.size(); i++)
        {
            currTrips += (maxTime / time[i]);
            if(currTrips >= totalTrips)
                return true;
        }
            
        return false;
    }
    
public:
    long long minimumTime(vector<int>& time, int totalTrips) 
    {
        long long low = 0, high = 1e15, ans = -1;
        
        while(low <= high)
        {
            long long mid = low + (high - low) / 2;
            
            if(check(time, totalTrips, mid))
                ans = mid, high = mid - 1;
            else
                low = mid + 1;
        }
        return ans;
    }
};