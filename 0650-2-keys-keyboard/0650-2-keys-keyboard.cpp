class Solution {
    
    int solve(int chars, bool copied, int &n, int copiedlen)
    {
        if(chars == n)
            return 0;
        if(chars > n)
            return 2000;
        if(copied == false)
        {
            return 1 + solve(chars, true, n, chars);
        }
        else {
            if(copiedlen == chars) {
                return 1 + solve(chars + chars, true, n, chars);
            }
            else {
                int way1 = 1 + solve(chars + copiedlen, true, n, copiedlen);
                int way2 = 1 + solve(chars, true, n, chars);
                return min(way1, way2);
            }
        }
    }
    
public:
    int minSteps(int n) {
        
        // int chars = 1;
        return solve(1, 0, n, 0);
    }
};