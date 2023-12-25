// https://leetcode.com/problems/minimum-number-game/

class Solution
{
public:
    vector<int> numberGame(vector<int> &nums)
    {
        int n = nums.size();
        sort(begin(nums), end(nums));
        for (int i = 0; i < n; i += 2)
            swap(nums[i], nums[i + 1]);
        return nums;
    }
};