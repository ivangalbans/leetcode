// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/description/

class Solution
{
public:
    int minimumPushes(string word)
    {
        int n = word.length();
        int ans = 0;
        int i;
        for (i = 1; i <= n / 8; ++i)
            ans += i * 8;
        return ans + i * (n % 8);
    }
};