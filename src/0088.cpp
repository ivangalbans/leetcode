// https://leetcode.com/problems/merge-sorted-array/description/

// Memory O(m + n)

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

// Memory O(1)

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (j >= 0)
        {
            if (i >= 0 && nums1[i] >= nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
    }
};