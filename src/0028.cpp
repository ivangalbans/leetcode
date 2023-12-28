// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

class Solution
{
public:
    int strStr(string t, string p)
    {
        int n = t.length(), m = p.length();
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (t[i] == p[j])
            {
                ++i;
                ++j;
                if (j == m)
                    return i - j;
            }
            else
            {
                i = i - j + 1;
                j = 0;
            }
        }

        return -1;
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

    int strStr(string t, string p)
    {
        int n = t.length(), m = p.length();

        auto pi = compute_pi(p);
        for (int i = 0, k = 0; i < n; ++i)
        {
            while (k >= 0 && p[k] != t[i])
                k = pi[k];
            if (++k >= m)
                return i - k + 1;
        }

        return -1;
    }
};