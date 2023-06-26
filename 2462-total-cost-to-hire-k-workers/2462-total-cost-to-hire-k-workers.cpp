// <--------------------Jai Shree Babosa-------------------->

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf INT_MAX
const int mod = 1e9 + 7;
struct compare
{
    bool operator()(const int &a, const int &b)
    {
        return a > b;
    }
};
class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        int n = costs.size();
        ll total = 0;
        priority_queue<int, vector<int>, compare> left;
        priority_queue<int, vector<int>, compare> right;
        int i = 0, j = n - 1;

        int frequency = candidates;
        while (frequency-- && i<= j)
        {
            left.push(costs[i]);
            i++;
        }

        frequency = candidates;
        while (frequency-- && i<= j)
        {
            right.push(costs[j]);
            j--;
        }

        for (int session = 0; session < k; session++)
        {
            if (left.size() && right.size() && left.top() < right.top())
            {
                total += left.top();
                left.pop();
                if (i <= j)
                {
                    left.push(costs[i]);
                    i++;
                }
            }
            else if (left.size() && right.size() && right.top() < left.top())
            {
                total += right.top();
                right.pop();
                if (i <= j)
                {
                    right.push(costs[j]);
                    j--;
                }
            }
            else if (left.size() == 0)
            {
                total += right.top();
                right.pop();
                if (i <= j)
                {
                    right.push(costs[j]);
                    j--;
                }
            }
            else if (right.size() == 0)
            {
                total += left.top();
                left.pop();
                if (i <= j)
                {
                    left.push(costs[i]);
                    i++;
                }
            }
            else
            {
                total += left.top();
                left.pop();
                if (i <= j)
                {
                    left.push(costs[i]);
                    i++;
                }
            }
            // cout << total << " " << endl;
        }

        return total;
    }
};