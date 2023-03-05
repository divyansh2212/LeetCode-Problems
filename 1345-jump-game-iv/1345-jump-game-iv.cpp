class Solution {

    int bfs(unordered_map<int, vector<int>> &mp, vector<int>& arr, int &n)
    {
        queue<int> q;
        q.push(0);
        vector<bool> visited(n, false);
        
        int steps = 0;
        while(!q.empty())
        {
            steps++;
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                auto front = q.front();
                q.pop();
                
                visited[front] = true;
                
                for(auto &child : mp[arr[front]])
                {
                    if(!visited[child])
                    {
                        q.push(child);
                        if(child == n - 1)
                            return steps;
                    }
                }
                mp[arr[front]].clear();
                
                
                if(front - 1 == n - 1 || front + 1 == n - 1)
                    return steps;
                    
                if(front - 1 >= 0 && !visited[front - 1])
                    q.push(front - 1);
                if(front + 1 < n && !visited[front + 1])
                    q.push(front + 1);
            }
        }
        return 0;
    }
    
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++)
            mp[arr[i]].push_back(i);
        
        
        return bfs(mp, arr, n);
    }
};