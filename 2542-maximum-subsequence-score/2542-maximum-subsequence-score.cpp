class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n = nums1.size(); long long ans = 0;
        vector<pair<int, int>> pairs;
        
        for(int i = 0; i < n; i++) {
            pairs.push_back({nums2[i], nums1[i]});
        }
        
        sort(pairs.begin(), pairs.end());
        reverse(pairs.begin(), pairs.end());
        
        long long sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < k - 1; i++) {
            pq.push(pairs[i].second);
            sum += pairs[i].second;
        }
        
        for(int i = k - 1; i < n; i++) {
            pq.push(pairs[i].second);
            sum += pairs[i].second;
            if(pq.size() > k) {
                int top = pq.top();
                pq.pop();
                sum -= top;
            }
            
            ans = max(ans, sum * pairs[i].first);
        }
        
        return ans;
    }
};