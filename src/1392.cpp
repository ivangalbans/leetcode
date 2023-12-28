// https://leetcode.com/problems/longest-happy-prefix/description/

// KMP - PI

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

    string longestPrefix(string s)
    {
        int n = s.length();
        auto pi = compute_pi(s);
        return s.substr(0, pi[n]);
    }
};