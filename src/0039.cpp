// https://leetcode.com/problems/combination-sum/description/

class Solution
{
public:
    void combinationSum(vector<int> &candidates, int index, vector<int> &nums, int sum, int target, vector<vector<int>> &ans)
    {
        if (sum > target)
            return;

        if (sum == target)
        {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < candidates.size(); ++i)
        {
            nums.push_back(candidates[i]);
            combinationSum(candidates, i, nums, sum + candidates[i], target, ans);
            nums.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> nums;
        combinationSum(candidates, 0, nums, 0, target, ans);
        return ans;
    }
};