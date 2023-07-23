// https://leetcode.com/problems/longest-increasing-subsequence/description/

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> buckets;
        buckets.push_back(nums[0]);

        for (int i = 1; i < n; ++i)
        {
            if (nums[i] > buckets.back())
                buckets.push_back(nums[i]);
            else
                buckets[distance(begin(buckets), lower_bound(begin(buckets), end(buckets), nums[i]))] = nums[i];
        }

        return buckets.size();
    }
};