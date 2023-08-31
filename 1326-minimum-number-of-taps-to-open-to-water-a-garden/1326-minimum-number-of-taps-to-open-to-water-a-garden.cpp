class Solution {

    public:

    int minTaps(int n, vector<int>& ranges) {

        vector<int> arr(n+1);

        for(int i = 0; i <= n; ++i) {
            int start = max(0, i - ranges[i]);
            int end = i + ranges[i];
            if(end > arr[start])
                arr[start] = end;
        }

        int pre = 0, cur = arr[0];
        int step =1;
        while(cur < n) {
            int next = -1;
            for(int i = pre + 1; i <= cur; ++i) {
                next = max(next, arr[i]);
            }

            if(next <= cur) return -1;
            pre = cur;
            cur = next;
            ++step;
        }
        return step;
    }
};