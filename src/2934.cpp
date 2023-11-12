// https://leetcode.com/problems/minimum-operations-to-maximize-last-elements-in-arrays/description/

class Solution
{
public:
    int minOperations(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m1 = *max_element(begin(nums1), end(nums1));
        int m2 = *max_element(begin(nums2), end(nums2));

        if (m1 != nums1[n - 1] && m2 != nums2[n - 1])
            return -1;

        if (m1 == nums1[n - 1] && m2 == nums2[n - 1])
            return 0;

        if (m1 != nums1[n - 1])
            swap(nums1, nums2);

        int gt2 = 0;
        for (auto x : nums2)
            if (x > nums2[n - 1])
                gt2++;

        swap(nums1[n - 1], nums2[n - 1]);
        int swp = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            if (nums1[i] > nums1[n - 1])
            {
                swap(nums1[i], nums2[i]);
                swp++;
            }

            if (nums1[i] > nums1[n - 1] || nums2[i] > nums2[n - 1])
                return -1;
        }

        return min(gt2, 1 + swp);
    }
};