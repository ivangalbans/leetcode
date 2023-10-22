// https://leetcode.com/problems/dungeon-game

// Recursion + Memoization

class Solution
{
public:
    const int oo = 1e9;

    int calculateMinimumHP(vector<vector<int>> &dungeon, vector<vector<int>> &memo, int i, int j, int n, int m)
    {
        // outside
        if (i == n || j == m)
            return oo;

        // base case
        if (i == n - 1 && j == m - 1)
            return dungeon[n - 1][m - 1] <= 0 ? abs(dungeon[n - 1][m - 1]) + 1 : 1;

        if (memo[i][j] != oo)
            return memo[i][j];

        int down = calculateMinimumHP(dungeon, memo, i + 1, j, n, m);
        int right = calculateMinimumHP(dungeon, memo, i, j + 1, n, m);

        int health = min(down, right) - dungeon[i][j];

        return memo[i][j] = max(1, health);
    }

    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> memo(n, vector<int>(m, oo));
        return calculateMinimumHP(dungeon, memo, 0, 0, n, m);
    }
};

// DP

class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        const int oo = 1e9;
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, oo));
        dp[n][m - 1] = dp[n - 1][m] = 1;

        for (int i = n - 1; i >= 0; --i)
            for (int j = m - 1; j >= 0; --j)
                dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);

        return dp[0][0];
    }
};