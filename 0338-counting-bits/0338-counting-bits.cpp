#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> arr(n + 1);
        for (int i = 0; i < n + 1; i++)
        {
            int cnt = 0;
            for (int j = 0; j < 32; j++)
            {
                if (i & (1 << j))
                    cnt++;
            }
            arr[i] = cnt;
        }

        return arr;
    }
};