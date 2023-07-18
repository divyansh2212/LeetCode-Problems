class Solution {
    public boolean isHappy(int n) {
        HashMap<Integer, Integer> hm = new HashMap<>();
        
        while(n != 1)
        {
            hm.put(n, 1);
            int newNumber = 0;
            while(n > 0)
            {
                int rem = n % 10;
                n /= 10;
                newNumber += (rem * rem);
            }
            if(hm.containsKey(newNumber)) {
                if(newNumber == 1)
                    return true;
                else
                    return false;
            }
            
            n = newNumber;
        }
        
        return (n == 1);
    }
}