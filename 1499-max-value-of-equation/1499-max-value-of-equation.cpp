class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        
        int n = points.size();
        int ans = INT_MIN;
        
        // y2 + x2 + y1 - x1
        
        priority_queue<pair<int, int>> pq;
        pq.push({points[0][1] - points[0][0], points[0][0]});
        
        for(int i = 1; i < n; i++)
        {
            int x = points[i][0], y = points[i][1];
            
            auto front = pq.top();
            
            int diff = front.first, x1 = front.second;
            
            if(x - x1 <= k)
            {
                ans = max(ans, diff + x + y);
            }
            else
            {
                while(pq.size())
                {
                    auto front = pq.top();
                    int diff = front.first, x1 = front.second;
                    if(x - x1 <= k)
                    {
                        ans = max(ans, diff + x + y);
                        break;
                    }
                    pq.pop();
                }
            }
            
            pq.push({y - x, x});
        }
        
        return ans;
    }
};