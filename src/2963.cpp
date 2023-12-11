// https://leetcode.com/problems/count-the-number-of-good-partitions/description/

class Solution
{
public:
    const int MOD = 1e9 + 7;

    int solve(int i, vector<int> &nums, unordered_map<int, int> &suff)
    {
        if (i >= nums.size() - 1)
            return 1;

        int r = suff[nums[i]];
        for (int j = i; j < nums.size() && j <= r; ++j)
            r = max(r, suff[nums[j]]);

        return r == nums.size() - 1 ? 1 : 2 * solve(r + 1, nums, suff) % MOD;
    }

    int numberOfGoodPartitions(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> suff;
        for (int i = n - 1; i >= 0; --i)
            if (!suff.count(nums[i]))
                suff[nums[i]] = i;

        return solve(0, nums, suff);
    }
};