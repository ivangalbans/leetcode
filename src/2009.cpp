// https://leetcode.com/problems/minimum-sum-of-mountain-triplets-ii/description/

class Solution
{
public:
    int minimumSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp1(n), dp2(n);
        dp1[0] = nums[0];
        dp2[n - 1] = nums[n - 1];

        for (int i = 1; i < n; ++i)
            dp1[i] = min(dp1[i - 1], nums[i]);

        for (int i = n - 2; i >= 0; --i)
            dp2[i] = min(dp2[i + 1], nums[i]);

        int sum = 1e9;
        for (int i = 1; i < n - 1; ++i)
            if (dp1[i - 1] < nums[i] && dp2[i + 1] < nums[i])
                sum = min(sum, dp1[i - 1] + nums[i] + dp2[i + 1]);

        return sum == 1e9 ? -1 : sum;
    }
};