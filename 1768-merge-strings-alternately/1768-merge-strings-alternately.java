class Solution {
    public String mergeAlternately(String word1, String word2) {
        String ans = "";
        
        int i = 0, j = 0;
        int count = 0;
        
        while(i < word1.length() && j < word2.length())
        {
            if(count % 2 == 0)
            {
                ans = ans + word1.charAt(i);
                i++;
            }
            else
            {
                ans = ans + word2.charAt(j);
                j++;
            }
            count++;
        }
        
        while(i < word1.length())
        {
            ans = ans + word1.charAt(i);
            i++;
        }
        
        while(j < word2.length())
        {
            ans = ans + word2.charAt(j);
            j++;
        }
        
        return ans;
    }
}