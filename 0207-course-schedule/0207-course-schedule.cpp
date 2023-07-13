class Solution
{
public:
    void dfs(vector<vector<int>> &prerequisites, int vtx, vector<bool> &visited, vector<bool> &dfsvisited, bool &flag)
    {
        visited[vtx] = true;
        dfsvisited[vtx] = true;

        for (auto &child : prerequisites[vtx])
        {
            if (visited[child] && dfsvisited[child])
                flag = false;
            else if (!visited[child])
                dfs(prerequisites, child, visited, dfsvisited, flag);
        }
        dfsvisited[vtx] = false;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {

        vector<vector<int>> graph(numCourses);

        for (int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0], v = prerequisites[i][1];
            graph[v].push_back(u);
        }

        bool flag = true;
        vector<bool> visited(numCourses, false);
        vector<bool> dfsvisited(numCourses, false);
        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
                dfs(graph, i, visited, dfsvisited, flag);
        }

        return flag;
    }
};