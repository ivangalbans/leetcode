// https://leetcode.com/problems/combination-sum-iv/description/

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