class Solution {
    public int totalMoney(int n) {
        
        int weeks = n / 7;
        int days = (n % 7);
        int ans = 0;
        
        int start = 28;
        for(int i = 1; i <= weeks; i++) {
            ans += start;
            start += 7;
        }
        
        start = weeks + 1;
        for(int i = 1; i <= days; i++)
        {
            ans += start;
            start++;
        }
        
        return ans;
    }
}