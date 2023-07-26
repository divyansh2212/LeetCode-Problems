class Solution {
public:
    int trailingZeroes(int n) {
        int twos = 0, fives = 0;
        for(int i = 2; i <= n; i++) {
            int num = i;
            while(num % 2 == 0) {
                num /= 2;
                twos++;
            }
            while(num % 5 == 0) {
                num /= 5;
                fives++;
            }
        }
        return min(twos, fives);
    }
};