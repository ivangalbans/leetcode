// https://leetcode.com/problems/minimum-sum-of-mountain-triplets-i/description/

class Solution
{
public:
    int minimumSum(vector<int> &nums)
    {
        int sum = 1e6;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                for (int k = j + 1; k < n; ++k)
                {
                    if (nums[i] < nums[j] && nums[k] < nums[j])
                        sum = min(sum, nums[i] + nums[j] + nums[k]);
                }
            }
        }

        return sum == 1e6 ? -1 : sum;
    }
};