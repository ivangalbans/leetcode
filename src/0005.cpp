// https://leetcode.com/problems/longest-palindromic-substring/description/

// Expand from center

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
};

// DP O(n^2)

class Solution
{
public:
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

// Hash Function

class Solution
{
public:
    static const int MAXN = 1000 + 5;
    long long fh[MAXN], bh[MAXN], prime[MAXN];
    long long mod = 1000000009;
    long long x = 1223;
    int n;
    bool init = true;

    void prime_power()
    {
        prime[0] = 1;
        for (int i = 1; i <= n; ++i)
            prime[i] = (prime[i - 1] * x) % mod;
    }

    void compute_hash(string &s)
    {
        fh[0] = bh[0] = 0;
        for (int i = 1, j = n; i <= n; j--, i++)
        {
            fh[i] = (fh[i - 1] + s[i - 1] * prime[i]) % mod;
            bh[j] = (bh[j + 1] + s[j - 1] * prime[i]) % mod;
        }
    }

    int palindrome_substring(string &s, int l, int r)
    {
        ++l;
        ++r;
        long long h1 = (fh[r] - fh[l - 1] + mod) % mod;
        long long h2 = (bh[l] - bh[r + 1] + mod) % mod;

        if (l <= n - r + 1)
        {
            int pow = (n - r + 1) - l;
            h1 = (h1 * prime[pow]) % mod;
        }
        else
        {
            int pow = l - (n - r + 1);
            h2 = (h2 * prime[pow]) % mod;
        }

        return h1 == h2;
    }

    int palindrome_substring_length(string &s, int k)
    {
        if (k == 0)
            return 0;
        for (int i = k - 1; i < n; ++i)
            if (palindrome_substring(s, i - k + 1, i))
                return i - k + 1;
        return -1;
    }

    pair<int, int> binary_search(string &s, int parity)
    {

        int lo = 1, hi = n;
        int pos = 0, len = 0;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (mid % 2 != parity)
                --mid;
            int index = palindrome_substring_length(s, mid);
            if (index != -1)
            {
                pos = index;
                len = mid;
                lo = mid + 2;
            }
            else
            {
                hi = mid - 1;
            }
        }

        return {pos, len};
    }

    string longestPalindrome(string s)
    {
        n = s.length();

        if (init)
        {
            prime_power();
            compute_hash(s);
            init = false;
        }

        auto [pos0, len0] = binary_search(s, 0);
        auto [pos1, len1] = binary_search(s, 1);

        return len0 > len1 ? s.substr(pos0, len0) : s.substr(pos1, len1);
    }
};

// Manacher

class Solution
{
public:
    vector<int> manacher(string text)
    {
        int n = text.size(), i, j, k = 0;
        vector<int> rad(n << 1);

        for (i = 0, j = 0; i < (n << 1); i += k, j = max(j - k, 0))
        {
            while (i - j >= 0 && i + j + 1 < (n << 1) &&
                   text[(i - j) >> 1] == text[(i + j + 1) >> 1])
                ++j;
            rad[i] = j;
            for (k = 1; i - k >= 0 && rad[i] - k >= 0 && rad[i - k] != rad[i] - k; ++k)
                rad[i + k] = min(rad[i - k], rad[i] - k);
        }
        rad.insert(rad.begin(), 0);
        return rad;
    }

    string longestPalindrome(string s)
    {
        auto lps = manacher(s);
        int i = max_element(begin(lps), end(lps)) - begin(lps);
        int len = lps[i];
        return s.substr((i - len) / 2, len);
    }
};