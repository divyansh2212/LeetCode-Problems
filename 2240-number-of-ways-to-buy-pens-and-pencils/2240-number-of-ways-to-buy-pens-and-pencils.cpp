class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        
        long long ans = 0;
        
        int pencils = 0;
        while(1)
        {
            int money = total;
            money -= cost2 * pencils;
            if(money < 0)
                break;
            int pens = money / cost1;
            pencils++;
            ans += (pens + 1);
        }
        return ans;
    }
};