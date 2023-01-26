class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        queue<pair<int,pair<int,int>>> q;
   
        q.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src]=0;
        
        while(!q.empty()){
            auto it= q.front();
            q.pop();
            int stp=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            if(stp>k)continue;
            for(auto it1 : adj[node]){
            int adjNode=it1.first;
            int W=it1.second;
                if(cost + W < dist[adjNode] && stp<=k){
                    dist[adjNode]=cost + W;
                    q.push({stp+1,{adjNode,cost + W}});
                }
            }   
        }
        
        if(dist[dst]==1e9)return -1;
        return dist[dst];      
    }
};