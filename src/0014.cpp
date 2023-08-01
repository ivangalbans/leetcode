// https://leetcode.com/problems/longest-common-prefix/description/

class Solution
{
public:
    int lcpLength(vector<string> &strs)
    {
        int ans = 0;
        for (int j = 0; j < strs[0].length(); ++j)
        {
            for (int i = 1; i < strs.size(); ++i)
            {
                if (j >= strs[i - 1].length() || j >= strs[i].length() || strs[i - 1][j] != strs[i][j])
                    return ans;
            }
            ans++;
        }
        return ans;
    }

    string longestCommonPrefix(vector<string> &strs)
    {
        string lcp = "";
        int lcpL = lcpLength(strs);

        for (int i = 0; i < lcpL; ++i)
            lcp += strs[0][i];

        return lcp;
    }
};