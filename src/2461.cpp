// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();

        unordered_map<int, int> freq;
        long long ans = 0, sum = 0;
        for (int i = 0; i < k - 1; ++i)
        {
            freq[nums[i]]++;
            sum += nums[i];
        }
        for (int i = k - 1; i < n; ++i)
        {
            int left = nums[i - (k - 1)], right = nums[i];

            freq[right]++;
            sum += right;

            if (freq.size() == k)
                ans = max(ans, sum);

            freq[left]--;
            sum -= left;
            if (freq[left] == 0)
                freq.erase(left);
        }

        return ans;
    }
};