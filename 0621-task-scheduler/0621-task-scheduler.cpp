class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        unordered_map<char, int> hsh;
        for(int i = 0; i < tasks.size(); i++) {
            hsh[tasks[i]]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto &it : hsh) {
            pq.push({it.second, it.first});
        }
        
        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            if(top.first > 1) 
            {
                top.first--;
                int middles = 0;
                vector<pair<int, char>> temp;
                while(!pq.empty())
                {
                    if(middles==n) break;
                    auto top2 = pq.top();
                    pq.pop();
                    top2.first--;
                    if(top2.first > 0) {
                        temp.push_back(top2);
                    }
                    middles++;
                }
                for(auto &it : temp) pq.push(it);
                pq.push(top);
                time += n;
            }
            time++;
        }
        
        return time;
    }
};