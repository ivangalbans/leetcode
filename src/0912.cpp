// https://leetcode.com/problems/sort-an-array/description/

class Solution
{
public:
    void merge(vector<int> &nums, int lo, int mid, int hi)
    {
        vector<int> temp(hi - lo + 1);
        int index = 0;
        int l = lo, r = mid + 1;
        while (l <= mid && r <= hi)
            temp[index++] = (nums[l] <= nums[r]) ? nums[l++] : nums[r++];
        while (l <= mid)
            temp[index++] = nums[l++];
        while (r <= hi)
            temp[index++] = nums[r++];
        copy(begin(temp), end(temp), begin(nums) + lo);

        return;
    }

    void merge_sort(vector<int> &nums, int lo, int hi)
    {
        if (lo >= hi)
            return;

        int mid = (lo + hi) / 2;
        merge_sort(nums, lo, mid);
        merge_sort(nums, mid + 1, hi);
        merge(nums, lo, mid, hi);

        return;
    }

    void merge_sort(vector<int> &nums)
    {
        merge_sort(nums, 0, nums.size() - 1);
        return;
    }

    vector<int> sortArray(vector<int> &nums)
    {
        merge_sort(nums);
        return nums;
    }
};