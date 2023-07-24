class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        
        while(n > 0)
        {
            if(n & 1)
                ans = ans * x;
            
            x = x*x;
            n = (n >> 1);
        }
        
        if(n < 0)
        {
            n = abs(n);
            while(n > 0)
            {
                if(n & 1)
                    ans = ans * x;

                x = x*x;
                n = (n >> 1);
            }
            return 1/ans;
        }      
        
        return ans;
    }
};