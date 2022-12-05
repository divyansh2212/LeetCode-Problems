class Solution {
public:
    int pivotInteger(int n) {
        int total = 0;
        for(int i = 0; i <= n; i++)
            total += i;
        
        int curr = 0;
        for(int i = 1; i <= n; i++)
        {
            curr += i;
            int left = total - curr + i;
            if(left == curr)
                return i;
        }
        return -1;
    }
};