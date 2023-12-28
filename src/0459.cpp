// https://leetcode.com/problems/repeated-substring-pattern/description/

// Using PI

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

    bool repeatedSubstringPattern(string s)
    {
        int n = s.length();
        auto pi = compute_pi(s);
        return pi[n] && n % (n - pi[n]) == 0;
    }
};

// KMP

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

    bool match(string t, string &p)
    {
        int n = t.length(), m = p.length();

        auto pi = compute_pi(p);
        for (int i = 0, k = 0; i < n; ++i)
        {
            while (k >= 0 && p[k] != t[i])
                k = pi[k];
            if (++k >= m)
                return true;
        }

        return false;
    }

    bool repeatedSubstringPattern(string s)
    {
        string ss = s + s;
        return match(ss.substr(1, ss.length() - 2), s);
    }
};