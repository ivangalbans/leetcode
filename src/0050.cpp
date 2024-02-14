// https://leetcode.com/problems/powx-n/description/

class Solution
{
public:
    double positivePow(double x, long long n)
    {
        double result = 1.0;
        while (n)
        {
            if (n % 2 == 1)
                result *= x;
            x *= x;
            n /= 2;
        }
        return result;
    }

    double myPow(double x, int n)
    {
        return n >= 0 ? positivePow(x, n) : 1 / positivePow(x, n * -1ll);
    }
};