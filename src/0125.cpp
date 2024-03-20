// https://leetcode.com/problems/valid-palindrome/description/
class Solution
{
public:
    bool checkPalindrome(string s)
    {
        int n = s.length();
        for (int i = 0; i < n / 2; ++i)
            if (s[i] != s[n - 1 - i])
                return false;
        return true;
    }

    bool isPalindrome(string s)
    {
        int n = s.length();
        string cleanedS = "";
        for (int i = 0; i < n; ++i)
            if (isalpha(s[i]) || isalnum(s[i]))
                cleanedS += tolower(s[i]);
        return checkPalindrome(cleanedS);
    }
};