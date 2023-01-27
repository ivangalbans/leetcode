// https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/description/

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        sort(begin(nums), end(nums));

        int i = 0;
        for (int j = 0; i < n, j < n; i += 1, j += 2)
            ans[j] = nums[i];

        for (int j = 1; i < n, j < n; i += 1, j += 2)
            ans[j] = nums[i];

        return ans;
    }
};