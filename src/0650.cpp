
// DP

class Solution
{
public:
    int minSteps(int n)
    {
        vector<int> dp(n + 1);

        for (int i = 2; i <= n; ++i)
        {
            dp[i] = i;
            for (int j = 2; j * j <= i; ++j)
            {
                if (i % j == 0)
                {
                    int d1 = j, d2 = i / j;
                    dp[i] = min(dp[i], dp[d1] + d2);
                    dp[i] = min(dp[i], dp[d2] + d1);
                }
            }
        }

        return dp[n];
    }
};