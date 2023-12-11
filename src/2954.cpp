// https://leetcode.com/problems/count-the-number-of-infection-sequences/description/

class Solution
{
public:
    const long long MOD = 1e9 + 7;

    long long mod_mult(long long a, long long b, long long mod)
    {
        long long x = 0;
        while (b)
        {
            if (b & 1)
                x = (x + a) % mod;
            a = (a << 1) % mod;
            b >>= 1;
        }
        return x;
    }

    long long mod_pow(long long a, long long n, long long mod)
    {
        long long x = 1;
        while (n)
        {
            if (n & 1)
                x = mod_mult(x, a, mod);
            a = mod_mult(a, a, mod);
            n >>= 1;
        }
        return x;
    }

    long long gcd(long long a, long long b, long long &x, long long &y)
    {
        if (b == 0)
        {
            x = 1;
            y = 0;
            return a;
        }
        long long r = gcd(b, a % b, y, x);
        y -= a / b * x;
        return r;
    }

    long long inverse(long long a, long long m)
    {
        long long x, y;
        if (gcd(a, m, x, y) != 1)
            return 0;
        return (x % m + m) % m;
    }

    int numberOfSequence(int n, vector<int> &sick)
    {
        vector<long long> fact_mod(n), power2_mod(n);
        fact_mod[0] = fact_mod[1] = 1;
        power2_mod[0] = 1;
        power2_mod[1] = 2;
        for (int i = 2; i < n; ++i)
        {
            fact_mod[i] = (fact_mod[i - 1] * i) % MOD;
            power2_mod[i] = (power2_mod[i - 1] * 2) % MOD;
        }

        vector<int> groups;
        int l = -1;
        for (auto x : sick)
        {
            groups.push_back(x - l - 1);
            l = x;
        }
        groups.push_back(n - l - 1);

        long long num = 1, den = 1;

        int total = 0;
        for (int i = 0; i < groups.size(); ++i)
        {
            total += groups[i];
            den = (den * fact_mod[groups[i]]) % MOD;
            if (i != 0 && i != groups.size() - 1)
                num = (num * power2_mod[max(0, groups[i] - 1)]) % MOD;
        }

        num = (num * fact_mod[total]) % MOD;

        return (num * inverse(den, MOD)) % MOD;
    }
};