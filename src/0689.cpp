// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/description/

class Solution
{
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();

        vector<int> sum(n + 1); // sum[i] sum of the nums[1..i]
        for (int i = 1; i <= n; ++i)
            sum[i] = sum[i - 1] + nums[i - 1];

        vector<int> left_dp(n, 0); // left_dp[i] index of the max subarray sum from nums[0..i]
        for (int best = 0, l = 0, r = k - 1; r < n; ++l, ++r)
        {
            int subarr_sum = sum[r + 1] - sum[l];
            if (subarr_sum > best)
            {
                best = subarr_sum;
                left_dp[r] = l;
            }
            else
            {
                left_dp[r] = left_dp[r - 1];
            }
        }

        vector<int> right_dp(n, n - k); // right_dp[i] index of the max subarray sum from nums[i..n-1]
        for (int best = 0, l = n - k, r = n - 1; l >= 0; --l, --r)
        {
            int subarray_sum = sum[r + 1] - sum[l];
            if (subarray_sum >= best)
            {
                best = subarray_sum;
                right_dp[l] = l;
            }
            else
            {
                right_dp[l] = right_dp[l + 1];
            }
        }

        vector<int> indexes;
        for (int best = 0, i = k, j = i + k - 1; j < n - k; ++i, ++j)
        {
            int l = left_dp[i - 1], m = i, r = right_dp[j + 1];
            int three_sum = (sum[l + k] - sum[l]) + (sum[m + k] - sum[m]) + (sum[r + k] - sum[r]);
            if (three_sum > best)
            {
                best = three_sum;
                indexes = {l, m, r};
            }
        }

        return indexes;
    }
};
