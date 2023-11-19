// https://leetcode.com/problems/maximum-xor-product/description/

class Solution
{
public:
    int maximumXorProduct(long long a, long long b, int n)
    {
        long long mod = 1e9 + 7;
        long long x = 0ll;
        for (int i = n - 1; i >= 0; --i)
        {
            long long bit = (1ll << i);
            if ((min(a, b) & bit) == 0)
            {
                a ^= bit;
                b ^= bit;
            }
        }
        return (a % mod) * (b % mod) % mod;
    }
};