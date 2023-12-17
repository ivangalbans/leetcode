// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/

class Solution
{
public:
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(begin(nums), end(nums));

        vector<vector<int>> ans;
        for (int i = 0; i + 2 < n; i += 3)
            if (nums[i + 2] - nums[i] <= k)
                ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
            else
                return {};

        return ans;
    }
};