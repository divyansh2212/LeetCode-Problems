class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int n = arr.size();
        int lo = 0, hi = n - 1;
        int ans;
        
        while(lo <= hi) {
            int mid = lo + (hi-lo) / 2;
            
            if(mid+1<n && arr[mid] < arr[mid + 1]) {
                lo = mid + 1;
            }
            else {
                ans = mid;
                hi = mid - 1;
            }
        }
        
        return ans;
    }
};