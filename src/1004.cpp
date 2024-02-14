// https://leetcode.com/problems/max-consecutive-ones-iii/description/

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int zeros = 0, ans = 0;
        for (int l = 0, r = 0; l < n; ++l)
        {
            while (r < n && zeros < k)
                if (nums[r++] == 0)
                    zeros++;
            while (r < n && nums[r] == 1)
                r++;

            ans = max(ans, (r - l));
            if (nums[l] == 0)
                zeros--;
        }

        return ans;
    }
};