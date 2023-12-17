// https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/

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

    int dfs(vector<vector<int>> &grid, int i, int j, int m, int n, vector<vector<bool>> &visited)
    {
        visited[i][j] = true;

        int children = 0;
        for (int k = 0; k < 4; ++k)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            if (inside(x, y, m, n) && !visited[x][y] && grid[x][y])
                children += dfs(grid, x, y, m, n, visited);
        }

        return grid[i][j] + children;
    }

    int findMaxFish(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        int ans = 0;
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (!visited[i][j] && grid[i][j])
                    ans = max(ans, dfs(grid, i, j, m, n, visited));

        return ans;
    }
};