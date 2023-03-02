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
    void merge(int start, int end, vint &nums, int &diff, ll &ans)
    {
        if (start == end)
            return;
        int mid = (start) + (end - start) / 2;

        int l = start, r = mid + 1;
        while (l <= mid && r <= end)
        {
            if (nums[l] <= nums[r] + diff)
            {
                ans += (end - r + 1);
                l++;
            }
            else
                r++;
        }

        int len1 = mid - start + 1, len2 = end - mid, mainArray = start;
        vint firstArray(len1), secondArray(len2);

        for (int i = 0; i < len1; i++)
            firstArray[i] = nums[mainArray++];
        for (int i = 0; i < len2; i++)
            secondArray[i] = nums[mainArray++];

        l = 0, r = 0, mainArray = start;

        while (l < len1 && r < len2)
        {
            if (firstArray[l] < secondArray[r])
                nums[mainArray++] = firstArray[l++];
            else
                nums[mainArray++] = secondArray[r++];
        }

        while (l < len1)
            nums[mainArray++] = firstArray[l++];
        while (r < len2)
            nums[mainArray++] = secondArray[r++];
    }
    void mergeSort(int start, int end, vint &nums, int &diff, ll &ans)
    {
        if (start >= end)
            return;
        int mid = start + (end - start) / 2;
        mergeSort(start, mid, nums, diff, ans);
        mergeSort(mid + 1, end, nums, diff, ans);
        merge(start, end, nums, diff, ans);
    }

public:
    long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int diff)
    {
        int n = nums1.size();

        vint differences;
        for (int i = 0; i < n; i++)
            differences.pb(nums1[i] - nums2[i]);

        ll ans = 0;

        mergeSort(0, n - 1, differences, diff, ans);
        return ans;
    }
};