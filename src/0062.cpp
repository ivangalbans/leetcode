// https://leetcode.com/problems/unique-paths/description/

// Top Down + Memoization

class Solution
{
public:
    int uniquePaths(int i, int j, int m, int n, int memo[][100])
    {
        if (i == m && j == n)
            return 1;

        if (i > m || j > n)
            return 0;

        if (memo[i][j])
            return memo[i][j];

        return memo[i][j] = uniquePaths(i + 1, j, m, n, memo) + uniquePaths(i, j + 1, m, n, memo);
    }

    int uniquePaths(int m, int n)
    {
        int memo[100][100] = {0};
        return uniquePaths(0, 0, m - 1, n - 1, memo);
    }
};

// Bottom Up
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n));

        for (int i = 0; i < m; ++i)
            dp[i][0] = 1;
        for (int j = 0; j < n; ++j)
            dp[0][j] = 1;
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

        return dp[m - 1][n - 1];
    }
};