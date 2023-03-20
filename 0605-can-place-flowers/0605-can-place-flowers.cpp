class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        if(n == 0)
                return true;
        if(flowerbed.size() == 1)
        {
            if(flowerbed[0] == 0 && n == 1)
                return true;
            return false;
        }
        
        int ans = 0;
        for(int i = 0; i < flowerbed.size();)
        {
            cout << i << " ";
            if(flowerbed[i] == 0 && i - 1 >= 0 && flowerbed[i - 1] == 0 && i + 1 < flowerbed.size() && flowerbed[i + 1] == 0)
                ans++, flowerbed[i] = 1, i += 2;
            else if(i == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0)
                ans++, flowerbed[i] = 1, i += 2;
            else if(i == flowerbed.size() - 1 && flowerbed[i] == 0 && flowerbed[i - 1] == 0)
                ans++, flowerbed[i] = 1, i += 2;
            else
                i++;
        }
        
        // cout << ans;
        return (ans >= n);
    }
};