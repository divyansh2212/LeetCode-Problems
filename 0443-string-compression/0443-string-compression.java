class Solution {
    public int compress(char[] chars) {
        int n = chars.length;
        
        int i = 0;
        String ans = "";
        while(i < n)
        {
            int idx = i;
            int count = 0;
            while(i < n && chars[i] == chars[idx]) {
                i++;
                count++;
            }
            if(count == 1) {
                ans += chars[idx];
            }
            else {
                ans += chars[idx];
                ans += Integer.toString(count);
            }
        }
        
        for(i = 0; i < ans.length(); i++) {
            chars[i] = ans.charAt(i);
        }
        
        return ans.length();
    }
}