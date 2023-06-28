class Solution {
public:
    int longestString(int x, int y, int z) {
        
        int ans = 2*min(x, y);
        if(x > y || y > x)
            ans++;
        ans += z;
        
        return ans*2;
    }
};