// https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/description/

class Solution
{
public:
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};

    bool inside(int i, int j, int m, int n)
    {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    int bfs(vector<vector<int>> &grid, int m, int n)
    {
        deque<array<int, 3>> q;
        vector<vector<bool>> visited(m, vector<bool>(n));

        visited[0][0] = true;
        q.push_back({0, 0, 0});
        while (!q.empty())
        {
            auto [i, j, d] = q.front();
            q.pop_front();
            if (i == m - 1 && j == n - 1)
                return d;

            for (int k = 0; k < 4; ++k)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                if (inside(x, y, m, n) && !visited[x][y])
                {
                    visited[x][y] = true;
                    if (grid[x][y] == 0)
                        q.push_front({x, y, d});
                    else
                        q.push_back({x, y, d + 1});
                }
            }
        }

        return -1;
    }

    int minimumObstacles(vector<vector<int>> &grid)
    {
        return bfs(grid, grid.size(), grid[0].size());
    }
};