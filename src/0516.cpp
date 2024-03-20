// https://leetcode.com/problems/longest-palindromic-subsequence/

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i)
        {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; ++j)
                dp[i][j] = (s[i] == s[j]) ? 2 + dp[i + 1][j - 1] : max(dp[i + 1][j], dp[i][j - 1]);
        }
        return dp[0][n - 1];
    }
};