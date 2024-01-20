// https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-i/description/

class Solution
{
public:
    vector<int> buildFail(string p)
    {
        int m = p.size();
        vector<int> pi(m + 1, 0);

        int j = pi[0] = -1;

        for (int i = 1; i <= m; ++i)
        {
            while (j >= 0 && p[j] != p[i - 1])
                j = pi[j];
            pi[i] = ++j;
        }
        return pi;
    }

    vector<int> match(string t, string p)
    {
        auto pi = buildFail(p);
        int n = t.size(), m = p.size();
        int count = 0;
        vector<int> indexes;

        for (int i = 0, k = 0; i < n; ++i)
        {
            while (k >= 0 && p[k] != t[i])
                k = pi[k];
            if (++k >= m)
            {
                indexes.push_back(i - k + 1);
                ++count;
                k = pi[k];
            }
        }
        return indexes;
    }

    vector<int> beautifulIndices(string s, string a, string b, int k)
    {
        vector<int> ans;
        auto v1 = match(s, a);
        auto v2 = match(s, b);

        int j = 0;
        for (int i = 0, j = 0; i < v1.size(); ++i)
        {
            while (j < v2.size() && v2[j] <= v1[i])
                j++;
            if (j < v2.size() && abs(v1[i] - v2[j]) <= k)
                ans.push_back(v1[i]);
            else if (j > 0 && abs(v1[i] - v2[j - 1]) <= k)
                ans.push_back(v1[i]);
        }

        return ans;
    }
};