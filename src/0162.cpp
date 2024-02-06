// https://leetcode.com/problems/find-peak-element/

// Binary Search

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1 || nums[0] > nums[1])
            return 0;

        if (nums.back() > nums[n - 2])
            return n - 1;

        int lo = 1, hi = n - 2;
        while (true)
        {
            int mid = (lo + hi) / 2;

            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
                return mid;
            if (nums[mid] < nums[mid - 1])
                hi = mid - 1;
            else if (nums[mid] < nums[mid + 1])
                lo = mid + 1;
        }

        return -1;
    }
};

// Ternary Search

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (r - l > 3)
        {
            int m1 = (2 * l + r) / 3;
            int m2 = (l + 2 * r) / 3;
            if (nums[m1] < nums[m2])
                l = m1;
            else
                r = m2;
        }
        return max_element(begin(nums) + l, begin(nums) + r + 1) - begin(nums);
    }
};