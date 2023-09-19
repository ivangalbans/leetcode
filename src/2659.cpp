// https://leetcode.com/problems/make-array-empty/description/

class Solution
{
public:
    long long rotations(vector<int> &nums, int n)
    {
        vector<int> ids(n);
        iota(begin(ids), end(ids), 0);
        sort(begin(ids), end(ids), [&](int i, int j)
             { return nums[i] < nums[j]; });

        long long rot = 0;
        for (int i = 1; i < n; ++i)
            rot += ids[i - 1] < ids[i] ? 0 : n - i;

        return rot;
    }

    long long countOperationsToEmptyArray(vector<int> &nums)
    {
        int n = nums.size();
        return rotations(nums, n) + n;
    }
};