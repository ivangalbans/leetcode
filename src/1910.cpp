// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/

// KMP O(n + m)

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

    string removeOccurrences(string t, string p)
    {
        int n = t.length(), m = p.length();
        string ans = t;
        auto pi = compute_pi(p);
        vector<int> matched(n);
        int j = 0;
        for (int i = 0, k = 0; i < n; ++i)
        {
            ans[j++] = t[i];
            while (k >= 0 && p[k] != t[i])
                k = pi[k];
            matched[i] = matched[j - 1] = ++k;
            if (k >= m)
            {
                j -= m;
                k = j > 0 ? matched[j - 1] : 0;
            }
        }

        return ans.substr(0, j);
    }
};