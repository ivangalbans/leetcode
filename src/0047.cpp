// https://leetcode.com/problems/permutations-ii/description/

// Backtracking

class Solution
{
public:
    void uniquePermutations(vector<int> &nums, int index, vector<vector<int>> &ans)
    {
        if (index == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> st;
        for (int i = index; i < nums.size(); ++i)
        {
            if (!st.count(nums[i]))
            {
                st.insert(nums[i]);
                swap(nums[index], nums[i]);
                uniquePermutations(nums, index + 1, ans);
                swap(nums[index], nums[i]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        uniquePermutations(nums, 0, ans);
        return ans;
    }
};

// Next Permutation

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int k = n - 2;
        while (k >= 0 && nums[k] >= nums[k + 1])
            --k;

        if (k == -1)
        {
            for (int i = 0; i < n / 2; ++i)
                swap(nums[i], nums[n - 1 - i]);
            return;
        }

        int l = n - 1;
        while (l > k && nums[k] >= nums[l])
            --l;

        swap(nums[k], nums[l]);
        reverse(begin(nums) + k + 1, end(nums));
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> next(nums);
        do
        {
            nextPermutation(next);
            ans.push_back(next);
        } while (!equal(begin(nums), end(nums), begin(next)));
        return ans;
    }
};