// https://leetcode.com/problems/triangle/

// Memory: O(n^2)

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        const int oo = 10000000;
        vector<vector<int>> dp(n, vector<int>(n, oo));

        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                if (j - 1 >= 0)
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                if (j != i)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + triangle[i][j]);
            }
        }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};

// Memory: O(n)

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        const int oo = 10000000;
        vector<vector<int>> dp(2, vector<int>(n, oo));

        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                dp[i % 2][j] = (j - 1 >= 0) ? dp[(i - 1) % 2][j - 1] + triangle[i][j] : oo;
                if (j != i)
                    dp[i % 2][j] = min(dp[i % 2][j], dp[(i - 1) % 2][j] + triangle[i][j]);
            }
        }

        return *min_element(dp[(n - 1) % 2].begin(), dp[(n - 1) % 2].end());
    }
};
;