// https://leetcode.com/problems/partition-equal-subset-sum/description/

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(begin(nums), end(nums), 0);
        if (sum % 2 == 1)
            return false;

        int val = sum / 2;
        vector<bool> kp(val + 1);

        for (auto x : nums)
        {
            for (int i = val; i >= 0; --i)
            {
                if (kp[i] && i + x <= val)
                {
                    kp[i + x] = true;
                }
            }
            if (x <= val)
                kp[x] = true;
        }

        return kp[val];
    }
};