// https://leetcode.com/problems/count-substrings-that-differ-by-one-character/description/

class Solution
{
public:
    int countSubstrings(string s, string t)
    {
        int n = s.length(), m = t.length();
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                bool skipped = false;
                for (int k = 0; i + k < n && j + k < m; ++k)
                {
                    if (s[i + k] != t[j + k])
                    {
                        if (skipped)
                            break;
                        skipped = true;
                    }
                    ans += (skipped == true);
                }
            }
        }

        return ans;
    }
};