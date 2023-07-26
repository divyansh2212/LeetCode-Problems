class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        
        vector<int> people(n, 0);
        
        int i = 0;
        int distribution = 1;
        while(candies > 0)
        {
            if(distribution > candies) {
                distribution = candies;
            }
            candies -= distribution;
            people[i % n] += distribution;
            i++, distribution++;
        }
        
        return people;
    }
};