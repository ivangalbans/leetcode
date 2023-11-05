// https://leetcode.com/problems/coin-change

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        const int oo = 1e9;
        vector<int> dp(amount + 1, oo);

        dp[0] = 0;
        for (int i = 1; i <= amount; ++i)
            for (auto coin : coins)
                if (i - coin >= 0 && dp[i - coin] != oo)
                    dp[i] = min(dp[i], 1 + dp[i - coin]);

        return dp[amount] == 1e9 ? -1 : dp[amount];
    }
};