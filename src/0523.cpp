// https://leetcode.com/problems/continuous-subarray-sum/

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> prev;
        int mod_sum = 0;
        prev.insert({0, -1});
        for (int i = 0; i < nums.size(); ++i)
        {
            mod_sum = (mod_sum + nums[i]) % k;
            if (prev.count(mod_sum))
            {
                if (prev[mod_sum] + 1 < i)
                    return true;
            }
            else
            {
                prev.insert({mod_sum, i});
            }
        }
        return false;
    }
};