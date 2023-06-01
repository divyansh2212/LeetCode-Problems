class Solution
{
public:
    vector<pair<int, int>> moves = {{1, 0}, {1, -1}, {1, 1}, {0, 1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        queue<pair<int, int>> q;

        q.push({0, 0});

        grid[0][0] = 1;
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();

            int x = front.first, y = front.second;

            if (x == n - 1 && y == n - 1)
                return grid[x][y];

            for (auto &move : moves)
            {
                int currx = x + move.first, curry = y + move.second;

                if (currx >= 0 && curry >= 0 && currx < n && curry < n && grid[currx][curry] == 0)
                {
                    q.push({currx, curry});
                    grid[currx][curry] = grid[x][y] + 1;
                }
            }
        }
        return -1;
    }
};