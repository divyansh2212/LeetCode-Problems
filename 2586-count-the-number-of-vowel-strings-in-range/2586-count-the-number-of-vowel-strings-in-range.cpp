
class Solution
{
public:
    int vowelStrings(vector<string> &s, int left, int right)
    {
        int ans = 0;
        for (int i = left; i <= right; i++)
        {
            int x = s[i].length() - 1;
            if ((s[i][0] == 'a' || s[i][0] == 'e' || s[i][0] == 'i' || s[i][0] == 'o' || s[i][0] == 'u') 
                && (s[i][x] == 'a' || s[i][x] == 'e' || s[i][x] == 'i' || s[i][x] == 'o' || s[i][x] == 'u'))
                ans++;
        }
        return ans;
    }
};