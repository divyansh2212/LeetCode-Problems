// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
//     void dfs(vector<vector<int>> &prerequisites, int vtx, vector<bool> &visited, vector<bool> &dfsvisited, bool &flag, vector<int> &ans)
//     {
//         visited[vtx] = true;
//         dfsvisited[vtx] = true;

//         for (auto &child : prerequisites[vtx])
//         {
//             if (visited[child] && dfsvisited[child])
//                 flag = false;
//             else if (!visited[child])
//                 dfs(prerequisites, child, visited, dfsvisited, flag, ans);
//         }
//         dfsvisited[vtx] = false;
//         ans.push_back(vtx);
//     }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegrees(numCourses, 0);
        vector<int> ans;

        for (int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0], v = prerequisites[i][1];
            inDegrees[u]++;
            graph[v].push_back(u);
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
            if(inDegrees[i] == 0)
                q.push(i);
        
        while(!q.empty())
        {
            int front = q.front(); q.pop();
            ans.push_back(front);
            for(auto &child : graph[front])
            {
                inDegrees[child]--;
                if(inDegrees[child] == 0)
                    q.push(child);
            }
        }
        
        if(ans.size() != numCourses)
            return {};
        
        return ans;
    }
};