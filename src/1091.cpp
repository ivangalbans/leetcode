// https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

class Solution
{
public:
    bool inside(int i, int j, int n)
    {
        return i >= 0 && i < n && j >= 0 && j < n;
    }

    int bfs(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
        queue<array<int, 3>> q;

        if (grid[0][0] == 0)
        {
            q.push({1, 0, 0});
            grid[0][0] = 1;
        }

        while (!q.empty())
        {
            auto [d, i, j] = q.front();
            q.pop();
            if (i == n - 1 && j == n - 1)
                return d;

            for (int k = 0; k < 8; ++k)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                if (inside(x, y, n) && grid[x][y] == 0)
                {
                    q.push({d + 1, x, y});
                    grid[x][y] = 1;
                }
            }
        }

        return -1;
    }

    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        return bfs(grid);
    }
};