// https://leetcode.com/problems/partition-equal-subset-sum/description/

// Top down

class Solution
{
public:
    bool canSum(int i, vector<int> &nums, int n, vector<vector<int>> &memo)
    {
        if (n <= 0)
            return n == 0;

        if (i == nums.size())
            return false;

        if (memo[i][n] != -1)
            return memo[i][n] == 1 ? true : false;

        return memo[i][n] = (canSum(i + 1, nums, n - nums[i], memo) || canSum(i + 1, nums, n, memo));
    }

    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int sum = accumulate(begin(nums), end(nums), 0);
        if (sum % 2 == 1)
            return false;

        int val = sum / 2;
        vector<vector<int>> memo(n, vector<int>(val + 1, -1));
        return canSum(0, nums, val, memo);
    }
};

// Bottom up

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