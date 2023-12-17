// https://leetcode.com/problems/apply-operations-to-maximize-frequency-score/description/

class Solution
{
public:
    long long sum(vector<long long> &pref_sum, int i, int j)
    {
        return i == 0 ? pref_sum[j] : pref_sum[j] - pref_sum[i - 1];
    }

    long long cost(vector<int> &nums, vector<long long> &pref_sum, int i, int j)
    {
        int m = (i + j) / 2;
        long long am = nums[m];
        return am * (2 * m + 1 - i - j) + sum(pref_sum, m + 1, j) - sum(pref_sum, i, m);
    }

    int maxFrequencyScore(vector<int> &nums, long long k)
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
            while (r < n && cost(nums, pref_sum, l, r) <= k)
                r++;
            ans = max(ans, r - l);
        }

        return ans;
    }
};