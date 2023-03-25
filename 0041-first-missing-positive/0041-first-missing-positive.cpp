// <--------------------Jai Shree Babosa-------------------->

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vint vector<int>
#define vll vector<long long>
#define inf INT_MAX
const int mod = 1e9 + 7;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();

        int x;

        for (x = 1; x <= n + 1;)
        {
            int original = x;
            for (int i = 0; i < n; i++)
                if (nums[i] == x)
                    x++;

            for (int i = n - 1; i >= 0; i--)
                if (nums[i] == x)
                    x++;

            if (x == original)
                break;
        }

        return x;
    }
};