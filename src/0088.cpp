// https://leetcode.com/problems/merge-sorted-array/description/

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> temp(m + n);
        int index = 0;
        int l = 0, r = 0;

        while (l < m && r < ni)
            temp[index++] = (nums1[l] < nums2[r]) ? nums1[l++] : nums2[r++];
        while (l < m)
            temp[index++] = nums1[l++];
        while (r < n)
            temp[index++] = nums2[r++];
        copy(begin(temp), end(temp), begin(nums1));
    }
};