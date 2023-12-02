// https://leetcode.com/problems/k-radius-subarray-averages/description/

// Prefix Sum

class Solution
{
public:
    long long sum(vector<long long> &pref, int i, int j)
    {
        return i == 0 ? pref[j] : pref[j] - pref[i - 1];
    }
    vector<int> getAverages(vector<int> &nums, int k)
    {
        int n = nums.size();

        vector<long long> pref(n);
        pref[0] = nums[0];
        for (int i = 1; i < n; ++i)
            pref[i] = pref[i - 1] + nums[i];

        vector<int> avg(n, -1);
        for (int i = k; i + k < n; ++i)
            avg[i] = sum(pref, i - k, i + k) / (2 * k + 1);

        return avg;
    }
};