// <--------------------Jai Shree Babosa-------------------->

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vint vector<int>
#define vll vector<long long>
#define inf INT_MAX
const int mod = 1e9 + 7;

class Solution
{
    unordered_map<string, int> mp;
    void dfs(int node, vector<int> graph[], set<vint> &parent, int par, int &k, int &curr)
    {
        int original = curr;
        string s = "node is " + to_string(node + 1) + "parent is " + to_string(par + 1);
        if (mp.find(s) != mp.end())
        {
            curr += mp[s];
            return;
        }
        if (parent.find({node, par}) != parent.end())
            curr++;
        for (auto &child : graph[node])
        {
            if (child == par)
                continue;
            if (curr == k)
                return;
            dfs(child, graph, parent, node, k, curr);
        }
        mp[s] = curr - original;
    }

public:
    int rootCount(vector<vector<int>> &edges, vector<vector<int>> &guesses, int k)
    {
        int ans = 0;
        mp.clear();
        int n = edges.size() + 1;
        set<vint> parentExpected;
        vector<int> graph[n];

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int i = 0; i < guesses.size(); i++)
        {
            int u = guesses[i][0], v = guesses[i][1];
            parentExpected.insert({v, u});
        }

        for (int i = 0; i < n; i++)
        {
            int curr = 0;
            dfs(i, graph, parentExpected, -1, k, curr);
            if (curr >= k)
                ans++;
        }

        return ans;
    }
};