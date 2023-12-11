// https://leetcode.com/problems/double-modular-exponentiation/description/

class Solution
{
public:
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

    bool is_good(vector<int> &v, int target)
    {
        int a = v[0], b = v[1], c = v[2], m = v[3];
        return mod_pow(mod_pow(a, b, 10), c, m) == target;
    }

    vector<int> getGoodIndices(vector<vector<int>> &v, int target)
    {
        vector<int> ans;
        for (int i = 0; i < v.size(); ++i)
        {
            if (is_good(v[i], target))
                ans.push_back(i);
        }

        return ans;
    }
};