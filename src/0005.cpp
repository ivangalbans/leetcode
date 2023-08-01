// https://leetcode.com/problems/longest-palindromic-substring/description/

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        vector<int> ans = {1, 0};

        for (int center = 0; center < s.length(); ++center)
        {
            int lo = center - 1, hi = center + 1;
            while (lo >= 0 && center < s.length() && s[lo] == s[hi])
            {
                if (hi - lo + 1 > ans[0])
                    ans = {hi - lo + 1, lo};
                lo--;
                hi++;
            }

            lo = center - 1, hi = center;
            while (lo >= 0 && center < s.length() && s[lo] == s[hi])
            {
                if (hi - lo + 1 > ans[0])
                    ans = {hi - lo + 1, lo};
                lo--;
                hi++;
            }
        }

        return s.substr(ans[1], ans[0]);
    }

    // DP O(n^2)
    string longestPalindromeDP(string s)
    {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n));

        string lcp = "";
        lcp += s[0];

        for (int i = 0; i < n; ++i)
            dp[i][i] = true;
        for (int i = 1; i < n; ++i)
            if (s[i - 1] == s[i])
            {
                dp[i - 1][i] = true;
                lcp = s.substr(i - 1, 2);
            }

        for (int len = 3; len <= n; ++len)
        {
            for (int i = 0; i + len - 1 < n; ++i)
            {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                    if (len > lcp.length())
                        lcp = s.substr(i, len);
                }
            }
        }

        return lcp;
    }
};