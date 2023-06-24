const int MIN = -1e4, offset = 5000;
class Solution {
    int ans, n;
    vector<int> rods;
    int dp[21][2 * offset + 1];
public:
    int tallestBillboard(vector<int>& rods) {
        this->rods = rods;
        n = rods.size();

        memset(dp , -1 , sizeof(dp));

        int ans = solve(0, 0);
        if (ans < 0)return 0;

        else return ans;
    }

    int solve(int position, int diff) {

        if (position == n) {
            if (diff == 0)return 0;
            return MIN;
        }

        int &ans = dp[position][diff + offset];
        if (ans != -1)return ans;

        int opt1 = solve(position + 1 , diff);
        int opt2 = rods[position] + solve(position + 1 , diff + rods[position]);
        int opt3 = solve(position + 1 , diff - rods[position]);

        return ans = max({opt1, opt2, opt3});
    }
};