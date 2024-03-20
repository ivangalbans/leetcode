// https://leetcode.com/problems/shortest-distance-from-all-buildings/description/

class Solution
{
private:
    int m, n;
    int houses;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool inside(int i, int j)
    {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    int bfs(vector<vector<int>> &grid, int i, int j)
    {
        int dist = 0, c = 0;
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n));
        vector<vector<int>> d(m, vector<int>(n));

        q.push({i, j});
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k)
            {
                int next_i = x + dx[k];
                int next_j = y + dy[k];
                if (inside(next_i, next_j) && !visited[next_i][next_j] && grid[i][j] != 2)
                {
                    visited[next_i][next_j] = true;
                    d[next_i][next_j] = 1 + d[x][y];
                    if (grid[next_i][next_j] == 1)
                    {
                        dist += d[next_i][next_j];
                        ++c;
                    }
                    else if (grid[next_i][next_j] == 0)
                    {
                        q.push({next_i, next_j});
                    }
                }
            }
        }

        if (c < houses)
        {
            for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j)
                    if (visited[i][j] && grid[i][j] == 0)
                        grid[i][j] = 2;
            return INT_MAX;
        }

        return dist;
    }

public:
    int shortestDistance(vector<vector<int>> &grid)
    {
        m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1)
                    ++houses;

        int dist = INT_MAX;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 0)
                    dist = min(dist, bfs(grid, i, j));

        return dist == INT_MAX ? -1 : dist;
    }
};