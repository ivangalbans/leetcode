// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();

        if (n == 1)
            return nums[0] == target ? 0 : -1;

        int k = 0;
        while (k + 1 < n && nums[k] < nums[k + 1])
            ++k;
        ++k;

        vector<int> a(2 * n);
        for (int i = 0; i < n; ++i)
            a[i] = a[i + n] = nums[i];

        int lo = k, hi = n + k - 1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (a[mid] < target)
                lo = mid + 1;
            else if (a[mid] > target)
                hi = mid - 1;
            else
                return (mid < n) ? mid : (mid - n);
        }

        return -1;
    }
};