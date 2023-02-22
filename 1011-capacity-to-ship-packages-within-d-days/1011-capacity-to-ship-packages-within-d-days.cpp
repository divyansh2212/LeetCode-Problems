class Solution {
    
    bool check(vector<int> &weights, int &days, int mid)
    {
        int curr = 1, currSum = 0;
        
        for(int i = 0; i < weights.size(); i++)
        {
            if(weights[i] > mid)
                return false;
            currSum += weights[i];
            if(currSum > mid)
                curr++, currSum = weights[i];
        }
        return (curr <= days);
    }
    
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        
        int lo = 0, hi = 1e9, ans = 1e9;
        
        while(lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if(check(weights, days, mid))
                ans = mid, hi = mid - 1;
            else
                lo = mid + 1;
        }
        
        return ans;
    }
};