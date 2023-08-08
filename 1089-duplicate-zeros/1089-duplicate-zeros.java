class Solution {
    public void duplicateZeros(int[] arr) {
        ArrayList<Integer> list = new ArrayList<>();
        int n = arr.length;
        
        for(int i = 0; i < n; i++)
        {
            if(list.size() == n) {
                break;
            }
            if(arr[i] != 0) {
                list.add(arr[i]);
            }
            else {
                list.add(0);
                list.add(0);
            }
        }
        
        for(int i = 0; i < n; i++) {
            arr[i] = list.get(i);
        }
    }
}