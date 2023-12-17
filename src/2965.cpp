// https://leetcode.com/problems/find-missing-and-repeated-values/description/

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> nums(n * n + 1);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                nums[grid[i][j]]++;

        vector<int> ans(2);
        for (int i = 1; i <= n * n; ++i)
        {
            if (nums[i] == 0)
                ans[1] = i;
            if (nums[i] == 2)
                ans[0] = i;
        }

        return ans;
    }
};