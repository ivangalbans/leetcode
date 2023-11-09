// https://leetcode.com/problems/combination-sum-iv/description/

// Top down

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int n, vector<int> &memo)
    {
        if (n == 0)
            return 1;

        if (n < 0)
            return 0;

        if (memo[n] != -1)
            return memo[n];

        int ans = 0;
        for (auto num : nums)
            ans += combinationSum4(nums, n - num, memo);

        return memo[n] = ans;
    }

    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> memo(target + 1, -1);
        return combinationSum4(nums, target, memo);
    }
};

// Bottom Up

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<uint> dp(target + 1);

        dp[0] = 1;
        for (int i = 0; i <= target; ++i)
            for (auto num : nums)
                if (i + num <= target)
                    dp[i + num] += dp[i];

        return dp[target];
    }
};