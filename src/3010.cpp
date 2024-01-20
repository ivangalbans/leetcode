// https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/description/

class Solution
{
public:
    int minimumCost(vector<int> &nums)
    {
        int n = nums.size();
        int pos = min_element(begin(nums) + 1, end(nums)) - begin(nums);
        int best = INT_MAX;
        for (int i = 1; i < n; ++i)
            if (i != pos && nums[i] < best)
                best = nums[i];

        return nums[0] + nums[pos] + best;
    }
};