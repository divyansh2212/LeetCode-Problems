class Solution {
    public int search(int[] arr, int target) {
        
        int n = arr.length;
        
        int start = 0;
        int end = n - 1;
        int ans = -1;
        
        while(start <= end)
        {
            int mid = (start + end) / 2;
            
            if(arr[mid] == target)
                return mid;
            
            if(arr[mid] > target)
            {
                end = mid - 1;
            }
            else if(arr[mid] < target)
            {
                start = mid + 1;
            }
            
        }
        
        
        return -1;
    }
}