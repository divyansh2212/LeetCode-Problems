class Solution {
    
    int ans = -1;
   
    
    bool dfs2(vector<bool> &visited, vector<bool> &pathVisited, vector<int> adj[], int vtx)
    {
        visited[vtx] = true, pathVisited[vtx] = true;
        
        for(auto &child : adj[vtx])
        {
            if(!visited[child])
            {
                if(dfs2(visited, pathVisited, adj, child))
                    return true;
            }
            else if(pathVisited[child])
                return true;
        }
        
        pathVisited[vtx] = false;
        return false;

    }
    
    bool isCyclic(int &v, vector<int> adj[]) {
        
        vector<bool> visited(v, false);
        vector<bool> pathVisited(v, false);
        
        for(int i = 0; i < v; i++)
            if(!visited[i])
                if(dfs2(visited, pathVisited, adj, i))
                    return true;
        
        return false;
    }
    
public:
    int largestPathValue(string s, vector<vector<int>>& edges) {
        
        int n = s.length();
        vector<int> g[n];
        vector<int>indegree(n,0);
        
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            if(u == v)
                return -1;
            indegree[v]++;
            g[u].push_back(v);
        }
        
        if(isCyclic(n, g))
            return -1;
        
        vector<vector<int>>count(n,vector<int>(26,0));
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                count[i][s[i]-'a']++;   
            }
        }
        
        ans=0;
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int r=*max_element(count[p].begin(),count[p].end());
            ans=max(ans,r);
            for(auto v: g[p]){
                for(int i=0;i<26;i++){
                    count[v][i]=max(count[v][i],count[p][i]+(i==s[v]-'a'));
                }
                if(--indegree[v]==0){
                    q.push(v);
                }
            }
        }
        return ans;
    }
};