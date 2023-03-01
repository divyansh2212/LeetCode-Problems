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
    int maximumProduct(vector<int> &nums, int k)
    {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());

        while (k > 0)
        {
            int top = pq.top();
            pq.pop();
            top++;
            pq.push(top);
            k--;
        }

        int ans = 1;
        while (!pq.empty())
        {
            int top = pq.top();
            pq.pop();
            ans = (ans * 1LL * top) % mod;
        }

        return ans;
    }
};