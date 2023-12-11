// https://leetcode.com/problems/patching-array/

class Solution
{
public:
    int minPatches(vector<int> &nums, int target)
    {
        int n = nums.size();

        long long x = 0;
        int i = 0, ans = 0;
        while (x < target)
        {
            if (i < n && nums[i] <= x + 1)
            {
                x += nums[i];
                ++i;
            }
            else
            {
                x = 2 * x + 1;
                ++ans;
            }
        }

        return ans;
    }
};