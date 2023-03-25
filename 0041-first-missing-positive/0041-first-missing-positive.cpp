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

        int last = 0;
        unordered_set<int> st;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0)
                continue;
            if (nums[i] == last + 1)
                last++;

            if (nums[i] > last)
                st.insert(nums[i]);
        }
        
        // int size = st.size();
        while(1)
        {
            if(st.find(last + 1) != st.end())
                last++;
            else
                break;
        }

        return last + 1;
    }
};