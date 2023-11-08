// https://leetcode.com/problems/unique-paths-ii/

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