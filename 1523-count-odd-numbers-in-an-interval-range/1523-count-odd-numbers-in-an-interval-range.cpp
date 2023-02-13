class Solution {
public:
    int countOdds(int low, int high) {
        int freq = 0;
        for(int i = low; i <= high; i++)
            if(i % 2)
                freq++;
        return freq;
    }
};