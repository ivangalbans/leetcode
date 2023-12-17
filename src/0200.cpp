// https://leetcode.com/problems/number-of-islands/description/

// DFS

class Solution
{
public:
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};

    bool inside(int i, int j, int m, int n)
    {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    void dfs(vector<vector<char>> &grid, int i, int j, int m, int n, vector<vector<bool>> &visited)
    {
        visited[i][j] = true;
        for (int k = 0; k < 4; ++k)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            if (inside(x, y, m, n) && !visited[x][y] && grid[x][y] == '1')
                dfs(grid, x, y, m, n, visited);
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        int scc = 0;
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    dfs(grid, i, j, m, n, visited);
                    ++scc;
                }

        return scc;
    }
};