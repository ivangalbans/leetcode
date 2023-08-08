// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/

class Solution
{
public:
    vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int m, n;

    int dfs(vector<vector<int>> &a, vector<vector<int>> &dp, int x, int y)
    {
        if (dp[x][y])
            return dp[x][y];

        for (auto d : dir)
        {
            int x1 = x + d.first;
            int y1 = y + d.second;
            if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && a[x1][y1] > a[x][y])
                dp[x][y] = max(dp[x][y], 1 + dfs(a, dp, x1, y1));
        }

        return max(dp[x][y], 1);
    }

    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        m = matrix.size();
        n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n));

        int ans = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!dp[i][j])
                {
                    dp[i][j] = dfs(matrix, dp, i, j);
                    ans = max(ans, dp[i][j]);
                }
            }
        }

        return ans;
    }
};