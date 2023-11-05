// https://leetcode.com/problems/ones-and-zeroes

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (auto &item : strs)
        {
            int zeros = count(item.begin(), item.end(), '0');
            int ones = count(item.begin(), item.end(), '1');

            for (int i = m; i >= zeros; --i)
                for (int j = n; j >= ones; --j)
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones]);
        }

        return dp[m][n];
    }
};

// Recursion + Memoization

class Solution
{
public:
    int solve(int memo[601][101][101], vector<vector<int>> &freq, int i, int m, int n, int M, int N)
    {

        if (m > M || n > N)
            return -1;

        if (i == freq.size())
            return 0;

        if (memo[i][m][n] != 0)
            return memo[i][m][n];

        return memo[i][m][n] = max(solve(memo, freq, i + 1, m, n, M, N),
                                   1 + solve(memo, freq, i + 1, m + freq[i][0], n + freq[i][1], M, N));
    }

    int findMaxForm(vector<string> &strs, int m, int n)
    {
        int len = strs.size();
        vector<vector<int>> freq(len, vector<int>(2));
        for (int i = 0; i < len; ++i)
        {
            int zeros = 0, ones = 0;
            for (int k = 0; k < strs[i].length(); ++k)
            {
                if (strs[i][k] == '0')
                    ++zeros;
                if (strs[i][k] == '1')
                    ++ones;
            }
            freq[i][0] = zeros;
            freq[i][1] = ones;
        }

        int memo[601][101][101] = {0};
        return solve(memo, freq, 0, 0, 0, m, n);
    }
};
