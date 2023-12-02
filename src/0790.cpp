// https://leetcode.com/problems/domino-and-tromino-tiling/description/

class Solution
{
public:
    int numTilings(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i)
        {
            dp[i] = 2 * dp[i - 1] + dp[i - 3];
            dp[i] %= MOD;
        }

        return dp[n];
    }
};