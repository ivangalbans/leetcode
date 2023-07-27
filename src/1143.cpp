// https://leetcode.com/problems/longest-common-subsequence/

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.length();
        int n = text2.length();
        int dp[m + 1][n + 1];

        dp[0][0] = 0;
        for (int i = 1; i <= m; ++i)
            dp[i][0] = 0;
        for (int j = 1; j <= n; ++j)
            dp[0][j] = 0;

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[m][n];
    }
};