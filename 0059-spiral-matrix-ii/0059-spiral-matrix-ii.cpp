// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ansmat(n, vector<int>(n));

        int firstRow = 0, lastRow = n - 1, firstcol = 0, lastcol = n - 1;

        int num = 1;

        while (firstRow <= lastRow && firstcol <= lastcol)
        {
            for (int i = firstcol; i < lastcol + 1; i++)
            {
                ansmat[firstRow][i] = num;
                num++;
            }
            firstRow++;

            for (int i = firstRow; i < lastRow + 1; i++)
            {
                ansmat[i][lastcol] = num;
                num++;
            }
            lastcol--;

            for (int i = lastcol; i >= firstcol; i--)
            {
                ansmat[lastRow][i] = num;
                num++;
            }
            lastRow--;

            for (int i = lastRow; i >= firstRow; i--)
            {
                ansmat[i][firstcol] = num;
                num++;
            }
            firstcol++;
        }

        return ansmat;
    }
};