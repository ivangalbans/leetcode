// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description/

class Solution
{
public:
    const int N = 1e5 + 1;
    int minOperations(vector<int> &nums, int x)
    {
        int n = nums.size();

        // suff[x] = i means sum(nums[i:]) = x
        unordered_map<int, int> suff(n);
        int suff_sum = 0;
        suff[0] = n;
        for (int i = n - 1; i >= 0; --i)
        {
            suff_sum += nums[i];
            if (!suff.count(suff_sum))
                suff[suff_sum] = i;
        }

        int ans = N;

        if (suff[x])
            ans = min(ans, n - suff[x]);

        int pref_sum = 0;
        for (int i = 0; i < n; ++i)
        {
            pref_sum += nums[i];
            if (pref_sum > x)
                break;
            int suff_sum = x - pref_sum;
            int j = suff.count(suff_sum) ? suff[suff_sum] : -1;
            if (i < j)
                ans = min(ans, i + 1 + n - j);
        }

        return ans == N ? -1 : ans;
    }
};

//  Find the max subarray such that the sum is sum-x
// Sliding windows

class Solution
{
public:
    int maxSubarraySum(vector<int> &nums, int k)
    {
        if (k == 0)
            return 0;

        int n = nums.size();
        int len = -1, sum = 0, r = 0;
        for (int l = 0; l < n; ++l)
        {
            while (r < n && sum + nums[r] <= k)
                sum += nums[r++];
            if (sum == k)
                len = max(len, r - l);
            sum -= nums[l];
        }
        return len;
    }

    int minOperations(vector<int> &nums, int x)
    {
        int n = nums.size();
        int sum = accumulate(begin(nums), end(nums), 0);
        int len = maxSubarraySum(nums, sum - x);
        return len >= 0 ? n - len : -1;
    }
};