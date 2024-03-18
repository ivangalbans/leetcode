// https://leetcode.com/problems/greatest-common-divisor-of-strings/description/

class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        int n = str1.length(), m = str2.length();
        return str1 + str2 == str2 + str1 ? str1.substr(0, gcd(n, m)) : "";
    }
};