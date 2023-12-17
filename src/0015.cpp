// https://leetcode.com/problems/3sum/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(begin(nums), end(nums));

        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i)
        {
            int target = -nums[i];

            // Two Sum
            int l = i + 1, r = n - 1;
            while (l < r)
            {
                int sum = nums[l] + nums[r];
                if (sum < target)
                    ++l;
                else if (sum > target)
                    --r;
                else
                {
                    vector<int> triplet = {nums[i], nums[l], nums[r]};
                    ans.push_back(triplet);
                    while (l < r && nums[l] == triplet[1])
                        ++l;
                    while (l < r && nums[r] == triplet[2])
                        --r;
                }
            }

            while (i + 1 < n && nums[i + 1] == nums[i])
                ++i;
        }

        return ans;
    }
};