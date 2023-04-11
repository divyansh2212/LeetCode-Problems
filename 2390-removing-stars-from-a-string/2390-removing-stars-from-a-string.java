class Solution {
    public String removeStars(String s) {
        
        int n = s.length();
        
        List<Boolean> visited = new ArrayList<Boolean>();
        
        for (int i = 0; i < n; i++) {
            visited.add(true);
        }
        // System.out.println(visited.size());
        
        int curr = 0;
        
        for(int i = n - 1; i >= 0; i--)
        {
            if(s.charAt(i) == '*')
            {
                visited.set(i, false);
                curr++;
            }
            else if(curr > 0)
            {
                curr--;
                visited.set(i, false);
            }
        }
        
        
        String ans = "";
        
        for(int i = 0; i < n; i++)
        {
            if(visited.get(i) == true)
                ans += (s.charAt(i));
        }
        
        return ans;
    }
}