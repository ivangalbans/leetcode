// https://leetcode.com/problems/subarray-sum-equals-k/

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size(), ans = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        int pref = 0;
        for (auto num : nums)
        {
            pref += num;
            ans += m[pref - k];
            m[pref]++;
        }
        return ans;
    }
};