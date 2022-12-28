class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        priority_queue<int> pq(piles.begin(), piles.end());
        
        while(k--)
        {
            int top = pq.top();
            pq.pop();
            top -= (top / 2);
            pq.push(top);
        }
        int sum = 0;
        
        while(pq.size())
        {
            int top = pq.top();
            pq.pop();
            sum += top;
        }
        
        return sum;
    }
};