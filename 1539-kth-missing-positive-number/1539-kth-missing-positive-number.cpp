class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int ans = -1;
        for(int i = 1; i <= 2000 && k > 0; i++)
        {
            int it = lower_bound(arr.begin(), arr.end(), i) - arr.begin();
            if(it == arr.size())
                k--, ans = i;
            else if(arr[it] != i)
                k--, ans = i;
        }
        return ans;
    }
};