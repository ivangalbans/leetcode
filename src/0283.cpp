// https://leetcode.com/problems/move-zeroes/description/

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0, zero = 0; i < n;)
        {
            if (nums[i] == 0)
                ++i;
            else
            {
                swap(nums[i], nums[zero]);
                i++;
                zero++;
            }
        }
    }
};