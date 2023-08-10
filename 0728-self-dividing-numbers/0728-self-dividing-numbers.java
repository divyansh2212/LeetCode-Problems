class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) 
    {
        List<Integer> list = new ArrayList<>();
        for(int i = left; i <= right; i++)
        {
            int temp = i;
            boolean flag = true;
            while(temp > 0)
            {
                int rem = temp % 10;
                temp /= 10;
                if(rem == 0 || (i % rem) != 0) {
                    flag = false;
                }
            }
            
            if(flag == true) {
                // System.out.print(i + " ");
                list.add(i);
            }
        }
        
        return list;
    }
}