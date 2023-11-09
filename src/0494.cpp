// https://leetcode.com/problems/target-sum/description/

// Combinations

class Solution
{
public:
    int findTargetSumWays(int i, int cnt, vector<int> &nums, int n)
    {
        if (i == nums.size())
            return cnt == n ? 1 : 0;

        return findTargetSumWays(i + 1, cnt + nums[i], nums, n) + findTargetSumWays(i + 1, cnt - nums[i], nums, n);
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        return findTargetSumWays(0, 0, nums, target);
    }
};