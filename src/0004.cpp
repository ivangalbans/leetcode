// Binary Search O(log(min(n, m)))

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();

        if (n > m)
            return findMedianSortedArrays(nums2, nums1);
        if (n == 0)
            return m % 2 == 0 ? (nums2[m / 2 - 1] + nums2[m / 2]) / 2.0 : nums2[m / 2];

        int lhalf = (n + m + 1) / 2;
        int lo1 = 0, hi1 = n;
        while (lo1 <= hi1)
        {
            int cut1 = (lo1 + hi1) / 2;
            int cut2 = lhalf - cut1;

            double l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            double l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            double r1 = cut1 >= n ? INT_MAX : nums1[cut1];
            double r2 = cut2 >= m ? INT_MAX : nums2[cut2];

            if (l1 <= r2 && l2 <= r1)
                return (n + m) % 2 == 0 ? (max(l1, l2) + min(r1, r2)) / 2.0 : max(l1, l2);
            else if (l1 > r2)
                hi1 = cut1 - 1;
            else
                lo1 = cut1 + 1;
        }

        return 0.0;
    }
};