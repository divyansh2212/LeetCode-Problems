// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf INT_MAX
const int mod = 1e9 + 7;

class Solution
{
    void f(vector<int> &dist, vector<int> graph[], int vtx, int curr, vector<bool> &visited)
    {
        visited[vtx] = true;
        dist[vtx] = curr;

        for (auto &child : graph[vtx])
        {
            if (visited[child])
                continue;
            f(dist, graph, child, curr + 1, visited);
        }
    }

public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        int n = edges.size();
        vector<int> graph[n];
        for (int i = 0; i < n; i++)
        {
            if (edges[i] == -1)
                continue;
            graph[i].push_back(edges[i]);
        }

        int node = -1;

        vector<int> dist1(n, inf);
        vector<bool> visited(n, false);
        dist1[node1] = 0;
        f(dist1, graph, node1, 1, visited);

        vector<int> dist2(n, inf);
        vector<bool> visited2(n, false);
        dist2[node2] = 0;
        f(dist2, graph, node2, 1, visited2);

        int distance = inf;
        for (int i = 0; i < n; i++)
        {
            if (dist1[i] == inf || dist2[i] == inf)
                continue;
            if (max(dist1[i], dist2[i]) < distance)
            {
                distance = max(dist1[i], dist2[i]);
                node = i;
            }
            else if (max(dist1[i], dist2[i]) == distance)
            {
                if (node == -1)
                    node = i;
                else if (i < node)
                    node = i;
            }
        }
        return node;
    }
};