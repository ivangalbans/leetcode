// https://leetcode.com/problems/maximal-square

// O(n * m * min(n, m))

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                dp[i][j] = (matrix[i - 1][j - 1] == '1' ? 1 : 0) + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];

        int area = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                for (int len = min(i, j); len >= 1; --len)
                    if (dp[i][j] - dp[i - len][j] - dp[i][j - len] + dp[i - len][j - len] == len * len)
                    {
                        area = max(area, len * len);
                        break;
                    }

        return area;
    }
};

// O (n*m)

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        int area = 0;
        for (int j = 0; j < m; ++j)
            if (matrix[0][j] == '1')
                dp[0][j] = area = 1;
        for (int i = 0; i < n; ++i)
            if (matrix[i][0] == '1')
                dp[i][0] = area = 1;

        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j)
                if (matrix[i][j] == '1')
                {
                    int len = min(dp[i - 1][j], dp[i][j - 1]);
                    if (dp[i - 1][j] != dp[i][j - 1] || matrix[i - len][j - len] == '1')
                        dp[i][j] = len + 1;
                    else
                        dp[i][j] = len;
                    area = max(area, dp[i][j] * dp[i][j]);
                }

        return area;
    }
};