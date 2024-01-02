// https://leetcode.com/problems/longest-duplicate-substring/description/

// Suffix Array

template <typename charT>
struct SuffixArray
{
    int n;
    vector<int> sa, rank, lcp;

    SuffixArray(const basic_string<charT> &s)
        : n(s.length() + 1), sa(n), rank(n), lcp(n)
    {
        vector<int> _sa(n), bucket(n);

        iota(sa.rbegin(), sa.rend(), 0);
        sort(next(sa.begin()), sa.end(), [&](int i, int j)
             { return s[i] < s[j]; });

        for (int i = 1, j = 0; i < n; ++i)
        {
            rank[sa[i]] = rank[sa[i - 1]] + (i == 1 || s[sa[i - 1]] < s[sa[i]]);
            if (rank[sa[i]] != rank[sa[i - 1]])
                bucket[++j] = i;
        }

        for (int len = 1; len <= n; len += len)
        {
            for (int i = 0, j; i < n; ++i)
            {
                if ((j = sa[i] - len) < 0)
                    j += n;
                _sa[bucket[rank[j]]++] = j;
            }

            sa[_sa[bucket[0] = 0]] = 0;

            for (int i = 1, j = 0; i < n; ++i)
            {
                if (rank[_sa[i]] != rank[_sa[i - 1]] ||
                    rank[_sa[i] + len] != rank[_sa[i - 1] + len])
                    bucket[++j] = i;

                sa[_sa[i]] = j;
            }

            copy(sa.begin(), sa.end(), rank.begin());
            sa.swap(_sa);

            if (rank[sa[n - 1]] == n - 1)
                break;
        }

        for (int i = 0, j = rank[lcp[0] = 0], k = 0; i < n - 1; ++i, ++k)
            while (k >= 0 && s[i] != s[sa[j - 1] + k])
                lcp[j] = k--, j = rank[sa[j] + 1];
    }
};

class Solution
{
public:
    string longestDupSubstring(string s)
    {
        SuffixArray<char> sa(s);
        int pos = 0, len = 0;
        for (int i = 1; i < sa.n; ++i)
        {
            if (sa.lcp[i] > 0 && sa.lcp[i] > len)
            {
                len = sa.lcp[i];
                pos = sa.sa[i];
            }
        }

        return s.substr(pos, len);
    }
};

// Give TLE
// Hash Function

class Solution
{
public:
    static const int MAXN = 30000 + 5;
    long long h1[MAXN], h2[MAXN], prime1[MAXN], prime2[MAXN], inv1[MAXN], inv2[MAXN];
    long long mod1 = 1000000007;
    long long mod2 = 1000000009;
    long long x = 31;
    int n;
    bool init = true;

    long long mod_pow(long long a, long long n, long long mod)
    {
        long long x = 1;
        while (n)
        {
            if (n & 1)
                x = (x * a) % mod;
            a = (a * a) % mod;
            n >>= 1;
        }
        return x;
    }

    void prime_power()
    {
        prime1[0] = inv1[0] = 1;
        prime2[0] = inv2[0] = 1;
        inv2[0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            prime1[i] = (prime1[i - 1] * x) % mod1;
            prime2[i] = (prime2[i - 1] * x) % mod2;
            inv1[i] = mod_pow(prime1[i], mod1 - 2, mod1);
            inv2[i] = mod_pow(prime2[i], mod2 - 2, mod2);
        }
    }

    void compute_hash(string &s)
    {
        h1[0] = h2[0] = 0;
        for (int i = 1, j = n; i <= n; j--, i++)
        {
            h1[i] = (h1[i - 1] + s[i - 1] * prime1[i]) % mod1;
            h2[i] = (h2[i - 1] + s[i - 1] * prime2[i]) % mod2;
        }
    }

    pair<long long, long long> hash(string &s, int l, int r)
    {
        ++l;
        ++r;
        long long xx = ((((h1[r] - h1[l - 1] + mod1) % mod1) * inv1[l]) % mod1);
        long long yy = ((((h2[r] - h2[l - 1] + mod2) % mod2) * inv2[l]) % mod2);
        return {xx, yy};
    }

    int solve(string &s, int len)
    {
        unordered_map<long long, unordered_map<long long, bool>> seen;

        for (int i = 0; i + len - 1 < n; ++i)
        {
            auto [xx, yy] = hash(s, i, i + len - 1);
            if (seen[xx][yy])
                return i;
            seen[xx][yy] = true;
        }

        return -1;
    }

    string longestDupSubstring(string s)
    {
        n = s.length();

        if (init)
        {
            prime_power();
            compute_hash(s);
            init = false;
        }

        int lo = 0, hi = n;
        int pos = 0, len = 0;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            int index = solve(s, mid);
            if (index != -1)
            {
                len = mid;
                pos = index;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }

        return s.substr(pos, len);
    }
};