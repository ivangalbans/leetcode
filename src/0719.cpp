// https://leetcode.com/problems/find-k-th-smallest-pair-distance/

class Solution
{
public:
    int countPairsLessOrEqualD(vector<int> &nums, int d)
    {
        int ans = 0, n = nums.size();
        for (int i = 0, j = 1; i < n; ++i)
        {
            while (j < n && nums[j] - nums[i] <= d)
                ++j;
            ans += (j - i - 1);
        }
        return ans;
    }

    int smallestDistancePair(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int lo = 0, hi = nums[n - 1];
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if (countPairsLessOrEqualD(nums, mid) < k)
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo;
    }
};