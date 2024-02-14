// https://leetcode.com/problems/missing-ranges/

class Solution
{
public:
    vector<vector<int>> findMissingRanges(vector<int> &nums, int lower, int upper)
    {

        nums.insert(begin(nums), lower - 1);
        nums.push_back(upper + 1);
        int n = nums.size();

        vector<vector<int>> ans;
        for (int i = 0; i + 1 < n; ++i)
            if (nums[i] + 1 != nums[i + 1])
                ans.push_back({nums[i] + 1, nums[i + 1] - 1});

        return ans;
    }
};