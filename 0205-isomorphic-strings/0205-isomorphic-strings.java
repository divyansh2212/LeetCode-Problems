class Solution {
    
    public static boolean check(String s, String t)
    {
        HashMap<Character, Character> hm = new HashMap<>();
        int n = s.length();
        
        for(int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            if(hm.containsKey(ch)) {
                char val = hm.get(ch);
                if(val != t.charAt(i)) {
                    return false;
                }
            }
            else {
                hm.put(ch, t.charAt(i));
            }
        }
        return true;
    }
    
    public boolean isIsomorphic(String s, String t) {
        
        return check(s, t) && check(t, s);
    }
}