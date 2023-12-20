// https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/

class Solution
{
public:
    long long sum(vector<long long> &pref_sum, int i, int j)
    {
        return i == 0 ? pref_sum[j] : pref_sum[j] - pref_sum[i - 1];
    }

    long long cost(vector<long long> &pref_sum, long long val, int i, int j)
    {
        return val * (j - i + 1) - sum(pref_sum, i, j);
    }

    int maxFrequency(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(begin(nums), end(nums));

        vector<long long> pref_sum(n);
        pref_sum[0] = nums[0];
        for (int i = 1; i < n; ++i)
            pref_sum[i] = pref_sum[i - 1] + nums[i];

        int ans = 0;
        for (int l = 0, r = 0; l < n; ++l)
        {
            while (r < n && cost(pref_sum, nums[r], l, r) <= k)
                ++r;
            ans = max(ans, r - l);
        }

        return ans;
    }
};