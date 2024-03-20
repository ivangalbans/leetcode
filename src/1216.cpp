// https://leetcode.com/problems/valid-palindrome-iii/description/

class Solution
{
private:
    int kRemoved(string &s, int l, int r, vector<vector<int>> &dp)
    {
        if (l >= r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        if (s[l] == s[r])
            return dp[l][r] = kRemoved(s, l + 1, r - 1, dp);

        return dp[l][r] = 1 + min(kRemoved(s, l + 1, r, dp), kRemoved(s, l, r - 1, dp));
    }

public:
    bool isValidPalindrome(string s, int k)
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return kRemoved(s, 0, n - 1, dp) <= k;
    }
};

// LCS

class Solution
{
private:
    int lcs(string &s, string &t)
    {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                dp[i][j] = (s[i - 1] == t[j - 1]) ? 1 + dp[i - 1][j - 1] : max(dp[i - 1][j], dp[i][j - 1]);
        return dp[n][m];
    }

public:
    bool isValidPalindrome(string s, int k)
    {
        string sr = s;
        reverse(begin(sr), end(sr));
        int tmp = lcs(s, sr);
        cout << tmp;
        return s.length() - tmp <= k;
    }
};