// https://leetcode.com/problems/maximum-repeating-substring/description/

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

    int kmp(string &t, string &p)
    {
        int n = t.length(), m = p.length();
        auto pi = compute_pi(p);
        int ans = 0;
        for (int i = 0, k = 0; i < n; ++i)
        {
            while (k >= 0 && p[k] != t[i])
                k = pi[k];

            ++k;
            ans = max(ans, k);
            if (k >= m)
                k = pi[k];
        }

        return ans;
    }

    int maxRepeating(string t, string p)
    {
        int n = t.length(), m = p.length();
        string pp = "";
        for (int i = 0; i < n / m; ++i)
            pp = pp + p;

        return kmp(t, pp) / p.length();
    }
};