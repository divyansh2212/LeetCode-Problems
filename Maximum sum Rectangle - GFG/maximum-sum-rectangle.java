//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int N, M, x, y;
            String S[] = read.readLine().split(" ");
            N = Integer.parseInt(S[0]);
            M = Integer.parseInt(S[1]);
            int a[][] = new int[N][M];
            for (int i = 0; i < N; i++) {
                String s[] = read.readLine().split(" ");
                for (int j = 0; j < M; j++) a[i][j] = Integer.parseInt(s[j]);
            }
            Solution ob = new Solution();
            System.out.println(ob.maximumSumRectangle(N, M, a));
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    
    private int kadane(int sum[])
    {
        int n = sum.length;
        int max_so_far = -1000000000;
        int curr = 0;
        
        for(int i = 0; i < n; i++)
        {
            curr += sum[i];
            if(curr < 0)
            {
                max_so_far = Math.max(max_so_far, curr);
                curr = 0;
            }
            else
                max_so_far = Math.max(max_so_far, curr);
        }
        
        return max_so_far;
    }
    
    int maximumSumRectangle(int n, int m, int mat[][]) {
        
        int sum[] = new int[n];
        int ans = Integer.MIN_VALUE;
        
        for(int c1 = 0; c1 < m; c1++)
        {
            Arrays.fill(sum, 0);
            for(int c2 = c1; c2 < m; c2++)
            {
                for(int r = 0; r < n; r++)
                {
                    sum[r] += mat[r][c2];
                }
                
                int currSum = kadane(sum);
                ans = Math.max(ans, currSum);
            }
            
        }
        
        return ans;
    }
};