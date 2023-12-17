// https://leetcode.com/problems/minimum-cost-to-make-array-equalindromic/description/

class Solution
{
public:
    bool is_palindrome(int num)
    {
        string s = to_string(num);
        int n = s.length();
        for (int i = 0; i < n / 2; ++i)
            if (s[i] != s[n - 1 - i])
                return false;
        return true;
    }

    long long minimumCost(vector<int> &nums)
    {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int median = nums[n / 2];

        int pal_left = median, pal_right = median;
        while (!is_palindrome(pal_left))
            pal_left--;
        while (!is_palindrome(pal_right))
            pal_right++;

        long long c1 = 0, c2 = 0;
        for (auto x : nums)
        {
            c1 += abs(x - pal_left);
            c2 += abs(x - pal_right);
        }

        return min(c1, c2);
    }
};