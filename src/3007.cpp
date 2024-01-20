// https://leetcode.com/problems/maximum-number-that-sum-of-the-prices-is-less-than-or-equal-to-k/

class Solution
{
public:
    long long price_sum(long long n, int x)
    {
        long long price = 0;
        for (int bit = x - 1; bit < 60; bit += x)
        {
            long long sz = (1ll << bit);
            long long blocks = n / sz;
            price += blocks / 2 * sz;
            if (blocks % 2 == 1)
                price += (n % sz);
        }
        return price;
    }

    long long findMaximumNumber(long long k, int x)
    {
        long long lo = 1, hi = 1e15;
        while (lo <= hi)
        {
            long long mid = (lo + hi) / 2;
            if (price_sum(mid + 1, x) <= k)
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        return lo - 1;
    }
};