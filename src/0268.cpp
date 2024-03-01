// https://leetcode.com/problems/missing-number/description/

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        return n * (n + 1) / 2 - accumulate(begin(nums), end(nums), 0);
    }
};

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int ans = n;
        for (int i = 0; i < n; ++i)
            ans ^= (nums[i] ^ i);
        return ans;
    }
};