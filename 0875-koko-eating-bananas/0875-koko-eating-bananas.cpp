class Solution {
    
    bool check(vector<int>& piles, int &h, int bananas)
    {
        int n = piles.size();
        long long time = 0;
        for(int i = 0; i < n; i++)
        {
            time += (piles[i] / bananas);
            if(piles[i] % bananas)
                time++;
            if(time > h)
                return false;
        }
        return true;
    }
    
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = 1e9, ans = -1;
        
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(check(piles, h, mid))
                ans = mid, high = mid - 1;
            else
                low = mid + 1;
        }
        
        return ans;
    }
};