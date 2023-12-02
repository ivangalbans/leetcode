// https://leetcode.com/problems/out-of-boundary-paths/description/

// Top down

class Solution
{
public:
    const int MOD = 1e9 + 7;
    long long findPaths(int m, int n, int k, int i, int j, int memo[][50][51])
    {
        if (i == -1 || i == m || j == -1 || j == n)
            return 1;

        if (k == 0)
            return 0;

        if (memo[i][j][k] != -1)
            return memo[i][j][k];

        return memo[i][j][k] = (findPaths(m, n, k - 1, i - 1, j, memo) +
                                findPaths(m, n, k - 1, i + 1, j, memo) +
                                findPaths(m, n, k - 1, i, j - 1, memo) +
                                findPaths(m, n, k - 1, i, j + 1, memo)) %
                               MOD;
    }

    int findPaths(int m, int n, int maxMove, int i, int j)
    {
        int memo[50][50][51];
        memset(memo, -1, sizeof(memo));
        return findPaths(m, n, maxMove, i, j, memo);
    }
};

// Bottom up

class Solution
{
public:
    int findPaths(int m, int n, int moves, int x, int y)
    {
        const int MOD = 1e9 + 7;
        long long dp[2][52][52] = {0};

        for (int nc = 0; nc < 2; ++nc)
        {
            for (int i = 1; i <= m; ++i)
                dp[nc][i][0] = dp[nc][i][n + 1] = 1;
            for (int j = 1; j <= n; ++j)
                dp[nc][0][j] = dp[nc][m + 1][j] = 1;
        }

        for (int k = 1; k <= moves; ++k)
            for (int i = 1; i <= m; ++i)
                for (int j = 1, nc = k % 2, np = (k - 1) % 2; j <= n; ++j)
                    dp[nc][i][j] = (dp[np][i - 1][j] + dp[np][i + 1][j] +
                                    dp[np][i][j - 1] + dp[np][i][j + 1]) %
                                   MOD;

        return dp[moves % 2][x + 1][y + 1];
    }
};