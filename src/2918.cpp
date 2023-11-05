// https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/

class Solution
{
public:
    long long minSum(vector<int> &nums1, vector<int> &nums2)
    {
        long long azero = count(begin(nums1), end(nums1), 0);
        long long asum = accumulate(begin(nums1), end(nums1), azero);

        long long bzero = count(begin(nums2), end(nums2), 0);
        long long bsum = accumulate(begin(nums2), end(nums2), bzero);

        if (asum == bsum)
            return asum;
        if (asum < bsum && azero > 0)
            return bsum;
        if (bsum < asum && bzero > 0)
            return asum;
        return -1;
    }
};