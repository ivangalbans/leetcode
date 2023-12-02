// https://leetcode.com/problems/subarray-product-less-than-k/description/

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int n = nums.size();

        int l = 0, pref = 1, ans = 0;
        for (int i = 0; i < n; ++i)
        {
            pref *= nums[i];
            while (pref >= k && l <= i)
            {
                pref /= nums[l];
                ++l;
            }
            ans += (i - l + 1);
        }

        return ans;
    }
};