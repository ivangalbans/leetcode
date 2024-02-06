// https://leetcode.com/problems/permutations/

class Solution
{
public:
    void allPermutations(vector<int> &nums, int index, vector<vector<int>> &ans)
    {
        if (index == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); ++i)
        {
            swap(nums[index], nums[i]);
            allPermutations(nums, index + 1, ans);
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permutations(vector<int> &nums, int k)
    {
        vector<vector<int>> ans;
        allPermutations(nums, 0, ans);
        return ans;
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = nums.size();
        return permutations(nums, n);
    }
};