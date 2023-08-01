class Solution {
    public boolean isIsomorphic(String s, String t) {
        
        HashMap<Character, Character> hm = new HashMap<>();
        int n = s.length();
        
        // checking for s
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
        
        // checking for t
        hm.clear();
        for(int i = 0; i < n; i++) {
            char ch = t.charAt(i);
            if(hm.containsKey(ch)) {
                char val = hm.get(ch);
                if(val != s.charAt(i)) {
                    return false;
                }
            }
            else {
                hm.put(ch, s.charAt(i));
            }
        }
        
        return true;
    }
}