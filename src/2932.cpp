// https://leetcode.com/problems/maximum-strong-pair-xor-i/description/

class Solution
{
public:
    int maximumStrongPairXor(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                if (abs(nums[i] - nums[j]) <= min(nums[i], nums[j]))
                    ans = max(ans, nums[i] ^ nums[j]);
            }
        }

        return ans;
    }
};