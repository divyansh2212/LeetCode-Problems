class Solution {
    public int maxVowels(String s, int k) {
        int n = s.length();
        int i = 0, j = 0;
        
        int vowels = 0, ans = 0;
        
        while(j < n)
        {
            if(s.charAt(j) == 'i' || s.charAt(j) == 'e' || s.charAt(j) == 'a' || s.charAt(j) == 'o' || s.charAt(j) == 'u')
                vowels++;
            if(j - i + 1 < k)
                j++;
            else
            {
                ans = Math.max(ans, vowels);
                if(s.charAt(i) == 'i' || s.charAt(i) == 'e' || s.charAt(i) == 'a' || s.charAt(i) == 'o' || s.charAt(i) == 'u')
                vowels--;
                i++; j++;
            }
        }
        
        return ans;
    }
}