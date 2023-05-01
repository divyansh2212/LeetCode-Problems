class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        int n = salary.size();
        double amt = 0;
        for(int i = 1; i < n - 1; i++)
            amt += salary[i];
        return amt/(n - 2);
    }
};