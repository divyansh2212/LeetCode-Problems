//{ Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*; 
class GFG{
    public static void main(String args[]) throws IOException { 
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        
        while(t-- > 0){
            int N = Integer.parseInt(read.readLine());
            String input_line[] = read.readLine().trim().split("\\s+");
            int A[]= new int[N];
            for(int i = 0; i < N; i++)
                A[i] = Integer.parseInt(input_line[i]);

            Solution ob = new Solution();
            long ans = ob.minDifference(N, A); 
            System.out.println(ans);
        }
    } 
} 
// } Driver Code Ends


class Solution 
{ 
    
    int bs(long prefix[], int lo, int hi, long sum, long temp)
    {
        int mid, index = -1;
        long first, second, diff = Long.MAX_VALUE;
        
        while(lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            first = prefix[mid] - temp;
            second = sum - prefix[mid];
            
            if(Math.abs(first - second)<diff)
            {
                index = mid;
                diff = Math.abs(first - second);
            }
            
            if(first < second)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        
        return index;
    }
    
    long minDifference(int n, int arr[]) 
    { 
        // code here
        long prefix[] = new long[n];
        prefix[0] = arr[0];
        
        for(int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + arr[i];
        }
        
        long ans = Long.MAX_VALUE, w, x, y, z;
        for(int i = 2; i < n - 1; i++)
        {
            int index = bs(prefix, 0, i - 1, prefix[i - 1], 0);
            w = prefix[index];
            x = prefix[i - 1] - w;
            
            index = bs(prefix, i, n - 1, prefix[n - 1], prefix[i - 1]);
            y = prefix[index] - w - x;
            z = prefix[n - 1] - w - x - y;
            
            ans = Math.min(ans, Math.max(Math.max(w, x), Math.max(y, z)) - Math.min(Math.min(w, x), Math.min(y, z)));
        }
        
        return ans;
    }
} 