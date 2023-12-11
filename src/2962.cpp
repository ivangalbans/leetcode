// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        long long ans = 0;
        int m = *max_element(begin(nums), end(nums));
        int cnt = 0;
        for (int l = 0, r = 0; l < n; ++l)
        {
            while (r < n && cnt < k)
            {
                if (nums[r] == m)
                    cnt++;
                r++;
            }
            if (cnt == k)
            {
                ans += (n - (r - 1));
            }
            if (nums[l] == m)
                cnt--;
        }

        return ans;
    }
};