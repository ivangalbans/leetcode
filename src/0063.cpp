// https://leetcode.com/problems/unique-paths-ii/

// Top Down + Memoization

class Solution
{
public:
    int dfs(int i, int j, int m, int n, vector<vector<int>> &grid, vector<vector<int>> &memo)
    {
        if (i > m || j > n)
            return 0;

        if (grid[i][j])
            return 0;

        if (i == m && j == n)
            return 1;

        if (memo[i][j] != -1)
            return memo[i][j];

        return memo[i][j] = dfs(i + 1, j, m, n, grid, memo) + dfs(i, j + 1, m, n, grid, memo);
    }

    int uniquePathsWithObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return dfs(0, 0, m - 1, n - 1, grid, memo);
    }
};

// Bottom Up
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));

        if (grid[0][0])
            return 0;

        dp[0][0] = 1 - grid[0][0];
        for (int i = 1; i < m; ++i)
            dp[i][0] = grid[i][0] ? 0 : dp[i - 1][0];
        for (int j = 1; j < n; ++j)
            dp[0][j] = grid[0][j] ? 0 : dp[0][j - 1];
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                dp[i][j] = grid[i][j] ? 0 : dp[i - 1][j] + dp[i][j - 1];

        return dp[m - 1][n - 1];
    }
};