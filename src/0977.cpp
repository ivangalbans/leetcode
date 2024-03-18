// https://leetcode.com/problems/squares-of-a-sorted-array/?envType=daily-question&envId=2024-03-02

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;

        int pos = lower_bound(begin(nums), end(nums), 0) - begin(nums);

        int l = pos - 1, r = pos;

        while (l >= 0 && r < n)
        {
            if (nums[l] * nums[l] <= nums[r] * nums[r])
                ans.push_back(nums[l] * nums[l--]);
            else
                ans.push_back(nums[r] * nums[r++]);
        }

        while (l >= 0)
            ans.push_back(nums[l] * nums[l--]);
        while (r < n)
            ans.push_back(nums[r] * nums[r++]);

        return ans;
    }
};

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;

        for (auto &num : nums)
            num *= num;

        int pos = min_element(begin(nums), end(nums)) - begin(nums);
        int l = pos - 1, r = pos;

        while (l >= 0 && r < n)
        {
            if (nums[l] <= nums[r])
                ans.push_back(nums[l--]);
            else
                ans.push_back(nums[r++]);
        }

        while (l >= 0)
            ans.push_back(nums[l--]);
        while (r < n)
            ans.push_back(nums[r++]);

        return ans;
    }
};