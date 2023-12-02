// https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int n = nums.size();
        // while iterating, dp[i] stores how many subarray sum gives module k is equal to i
        vector<int> dp(k);
        dp[0] = 1;

        int sum = 0, ans = 0;
        ;
        for (auto num : nums)
        {
            sum = (sum + (num % k) + k) % k;
            ans += dp[sum];
            dp[sum]++;
        }

        return ans;
    }
};