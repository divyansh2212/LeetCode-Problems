//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            int N = Integer.parseInt(read.readLine());
            Solution ob = new Solution();
            System.out.println(ob.countFactors(N));
        }
    }
}
// } Driver Code Ends


//User function Template for Java
class Solution{
    static int countFactors(int n) {
        ArrayList<Integer> factors = new ArrayList<>();
        int sqrt = (int)Math.sqrt(n);
        for(int i = 1; i <= sqrt; i++)
        {
            if(n % i == 0) 
            {
                factors.add(i);
                if((n/i) != i) 
                {
                    factors.add(n/i);
                }
            }
        }
        
        // for(int x : factors)
        //     System.out.print(x + " ");
        
        return factors.size();
    }
}