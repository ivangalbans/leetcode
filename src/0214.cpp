// https://leetcode.com/problems/shortest-palindrome/description/

class Solution
{
public:
    vector<int> compute_pi(string &p)
    {
        int m = p.length();
        vector<int> pi(m + 1, -1);

        for (int i = 1, j = -1; i <= m; ++i)
        {
            while (j >= 0 && p[j] != p[i - 1])
                j = pi[j];
            pi[i] = ++j;
        }

        return pi;
    }

    string shortestPalindrome(string s)
    {
        int n = s.length();
        string sr = s;
        reverse(sr.begin(), sr.end());
        string ss = s + "$" + sr;
        auto pi = compute_pi(ss);

        int to_add = n - pi.back();
        string suffr = s.substr(s.length() - to_add);
        reverse(suffr.begin(), suffr.end());

        return suffr + s;
    }
};