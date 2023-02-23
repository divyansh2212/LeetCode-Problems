class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int, int>> pq;
        int n = profits.size(), ans = 0;
        
        for(int i = 0; i < n; i++)
            pq.push({profits[i], capital[i]});
        
        while(k--)
        {
            vector<pair<int, int>> temp;
            int original = w;
            while(pq.size())
            {
                auto top = pq.top();
                pq.pop();
                int netgain = top.first, capita = top.second;
                if(netgain <= 0)
                    break;
                else if(capita > w)
                {
                    temp.push_back(top);
                    continue;
                }
                else
                {
                    w += netgain;
                    break;
                }
            }
            
            if(original == w)
                break;
            while(temp.size())
            {
                pq.push(temp.back());
                temp.pop_back();
            }
        }
        
        return w;
    }
};