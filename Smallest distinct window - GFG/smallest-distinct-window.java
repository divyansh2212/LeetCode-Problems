//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main(String[] args) throws IOException
	{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while(t-->0)
        {
            String str = br.readLine();
            
            Solution obj = new Solution();
            System.out.println(obj.findSubString(str));
            
        }
	}
}


// } Driver Code Ends


//User function Template for Java

class Solution {
    public int findSubString( String str) {
        // Your code goes here
        int ans = str.length();
        int n = ans;
        HashMap<Character, Integer> hashMap = new HashMap<Character, Integer>();
        
        for(int i = 0; i < n; i++)
        {
            if(hashMap.containsKey(str.charAt(i)) == false)
            {
                hashMap.put(str.charAt(i), 1);
            }
        }
        
        int totalChars = hashMap.size();
        hashMap.clear();
        
        int i = 0, j = 0;
        
        while(j < n)
        {
            int prev = 0;
            if(hashMap.containsKey(str.charAt(j)) == true)
            {
                prev = hashMap.get(str.charAt(j));
                // hashMap.remove(str.charAt(j));
            }
            hashMap.put(str.charAt(j), prev + 1);
                
            
            while(hashMap.size() == totalChars)
            {
                ans = Math.min(ans, j - i + 1);
                prev = hashMap.get(str.charAt(i));
                if(prev == 1)
                    hashMap.remove(str.charAt(i));
                else
                {
                    // hashMap.remove(str.charAt(i));
                    hashMap.put(str.charAt(i), prev - 1);
                }
                i++;    
            }
            
            j++;
        }
        
        return ans;
    }
}