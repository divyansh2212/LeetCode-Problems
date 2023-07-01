
#define ll long long

class Solution
{
public:
    void f(vector<int> &cookies, vector<int> &persons, int idx, int &ans)
    {
        if (idx == cookies.size())
        {
            int mx = INT_MIN;
            for (int i = 0; i < persons.size(); i++)
                mx = max(mx, persons[i]);

            ans = min(ans, mx);
            return;
        }

        for (int i = 0; i < persons.size(); i++)
        {
            persons[i] += cookies[idx];
            f(cookies, persons, idx + 1, ans);
            persons[i] -= cookies[idx];
        }
    }

    int distributeCookies(vector<int> &cookies, int k)
    {
        vector<int> persons(k, 0);
        int ans = INT_MAX;
        f(cookies, persons, 0, ans);

        return ans;
    }
};