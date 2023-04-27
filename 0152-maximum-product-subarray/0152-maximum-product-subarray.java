class Solution {
    public int maxProduct(int[] arr) {
        
        int n = arr.length;
        
        int maxproduct = arr[0];
        int l = 1, r = 1;
        
        for(int i = 0; i < n; i++)
        {
            l = (l * arr[i]);
            r = (r * arr[n - 1 - i]);
            maxproduct = Math.max(maxproduct, Math.max(l, r));
            if(l == 0)
                l = 1;
            if(r == 0)
                r = 1;
        }
        
        return maxproduct;
    }
}