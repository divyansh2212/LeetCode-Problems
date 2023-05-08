class Solution {
    public int diagonalSum(int[][] mat) {
        int n = mat.length;
        
        int ans = 0;
        int i = 0, j = 0;
        
        while(i < n)
        {
            ans += mat[i][j];
            i++; j++;
        }
        
        i = 0; j = n - 1;
        while(i < n)
        {
            ans += mat[i][j];
            i++; j--;
        }
        
        if(n % 2 == 1)
            ans -= mat[n / 2][n / 2];
        
        return ans;
    }
}