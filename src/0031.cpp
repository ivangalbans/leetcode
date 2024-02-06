// https://leetcode.com/problems/next-permutation/

// Source: https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();

        int k;
        for (k = n - 2; k >= 0; --k)
            if (nums[k] < nums[k + 1])
                break;

        // last permutation
        if (k == -1)
        {
            for (int i = 0; i < n / 2; ++i)
                swap(nums[i], nums[n - 1 - i]);
            return;
        }

        int l;
        for (l = n - 1; l > k; --l)
            if (nums[k] < nums[l])
                break;

        swap(nums[k], nums[l]);
        reverse(begin(nums) + k + 1, end(nums));
    }
};