class Solution {
    
    void dfs(int vtx, vector<int> graph[], vector<bool> &visited)
    {
        visited[vtx] = true;
        
        for(auto &child : graph[vtx])
            if(!visited[child])
                dfs(child, graph, visited);
    }
    
public:
    int numSimilarGroups(vector<string>& strs) {

        int n = strs.size();
        int m = strs[0].size();
        vector<int>graph[n];
        
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
               //we will check if they are similar or not
               int c = 0;
               for(int k=0;k<m;++k){
                   if(strs[i][k] != strs[j][k]){
                       c++;
                   }
               }
               //cout<<i<<" "<<j<<" "<<c<<"\n";
               if(c <= 2){
                  graph[i].push_back(j);
                  graph[j].push_back(i);
               }

            }
        }
        
        int ans = 0;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                ans++;
                dfs(i, graph, visited);
            }
        }
     
        return ans;
    }
};