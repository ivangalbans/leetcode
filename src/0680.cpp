// https://leetcode.com/problems/valid-palindrome-ii/description/

class Solution
{
public:
    bool isPalindrome(string &s, int l, int r)
    {
        while (l < r)
            if (s[l++] != s[r--])
                return false;
        return true;
    }

    bool validPalindrome(string s)
    {
        int n = s.length();
        int l = 0, r = n - 1;
        for (int l = 0, r = n - 1; l < n / 2; ++l, --r)
            if (s[l] != s[r])
                return isPalindrome(s, l, r - 1) || isPalindrome(s, l + 1, r);
        return true;
    }
};