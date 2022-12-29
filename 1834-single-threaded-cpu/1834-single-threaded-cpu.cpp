class Solution {
    
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> ans;
        priority_queue <vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        
        for(int i = 0; i < n; i++)
            tasks[i].push_back(i);
        
        sort(tasks.begin(), tasks.end());
        
        int i = 0;
        long long time = 0;
        
        while(i < n || pq.size())
        {
            if(pq.size() == 0)
                time = max(time, 0LL + tasks[i][0]);
            
            while(i < n && time >= tasks[i][0])
            {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }
            
            auto top = pq.top();
            pq.pop();
            time += top[0];
            ans.push_back(top[1]);
            
        }
        
       
        return ans;
    }
};