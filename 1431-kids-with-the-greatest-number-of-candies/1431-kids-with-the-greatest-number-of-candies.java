class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int maxi = -1;
        int n = candies.length;
        
        for(int i = 0; i < n; i++){
            maxi = Math.max(maxi, candies[i]);
        }
        
        List<Boolean> list = new ArrayList<>();
        
        for(int i = 0; i < n; i++){
            if(candies[i] + extraCandies >= maxi){
                list.add(true);
            }
            else{
                list.add(false);
            }
        }
        
        return list;
    }
}