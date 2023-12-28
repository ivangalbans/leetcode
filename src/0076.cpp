// https://leetcode.com/problems/minimum-window-substring/submissions/1128547777/

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int m = s.length(), n = t.length();
        pair<int, int> ans = {-1, m};

        unordered_map<int, int> occ;
        for (int i = 0; i < n; ++i)
            occ[t[i]]++;

        int len = 0;
        for (int l = 0, r = 0; l < m; ++l)
        {
            while (r < m && len != n)
                if (occ[s[r++]]-- > 0)
                    ++len;

            if (len == n && r - l < (ans.second - ans.first + 1))
                ans = {l, r - 1};

            if (++occ[s[l]] > 0)
                len--;
        }

        return ans.first == -1 ? "" : s.substr(ans.first, ans.second - ans.first + 1);
    }
};