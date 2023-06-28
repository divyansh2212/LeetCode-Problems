class Solution {

public:
    int makeTheIntegerZero(int num1, int num2) {
        
        if(num1 == 0)
            return 0;
        
        for(int i = 1; i <= 500; i++)
        {
            long long number = i *1LL* num2;
            long long reqd = num1 - number;
            int bits = __builtin_popcountll(reqd);
            if(i >= bits && i <= reqd)
                return i;
        }
        
        return -1;
    }
};