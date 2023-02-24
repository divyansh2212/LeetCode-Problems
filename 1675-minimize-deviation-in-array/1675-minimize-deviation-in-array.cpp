class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        int n = nums.size();
        priority_queue<int> pq;
        
        int mini = INT_MAX, ans = INT_MAX;
        for(auto &it : nums)
        {
            if(it % 2)
                it = (it * 2);
            mini = min(mini, it);
            pq.push(it);
        }
        
        while(pq.top() % 2 == 0)
        {
            int top = pq.top();
            pq.pop();
            ans = min(ans, top - mini);
            mini = min(mini, top / 2);
            pq.push(top / 2);
        }
        ans = min(ans, pq.top() - mini);
        
        return ans;
    }
};