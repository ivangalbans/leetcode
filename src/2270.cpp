// https://leetcode.com/problems/number-of-ways-to-split-array/description/

class Solution
{
public:
    long long query_sum(vector<long long> &acc, int l, int r)
    {
        return l == 0L ? acc[r] : (acc[r] - acc[l - 1]);
    }

    int waysToSplitArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<long long> acc(n);

        acc[0] = nums[0];
        for (int i = 1; i < n; ++i)
            acc[i] = acc[i - 1] + (long long)nums[i];

        int ans = 0;
        for (int i = 0; i < n - 1; ++i)
            if (query_sum(acc, 0, i) >= query_sum(acc, i + 1, n - 1))
                ++ans;

        return ans;
    }
};