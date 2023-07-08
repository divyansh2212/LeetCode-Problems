class Solution {
public:
    long long putMarbles(vector<int>& arr, int k) {
        int n = arr.size();
        
        priority_queue<int> pq;
        for(int i = 0; i < n - 1; i++) {
            pq.push(arr[i] + arr[i + 1]);
        }
        
        long maxm = 0;
        for(int i = 0; i < k - 1; i++) {
            maxm += pq.top();
            pq.pop();
        }
        
        priority_queue<int, vector<int>, greater<int>> pq2;
        for(int i = 0; i < n - 1; i++) {
            pq2.push(arr[i] + arr[i + 1]);
        }
        
        long minm = 0;
        for(int i = 0; i < k - 1; i++) {
            minm += pq2.top();
            pq2.pop();
        }
        
        return maxm - minm;
    }
};