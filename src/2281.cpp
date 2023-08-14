// https://leetcode.com/problems/sum-of-total-strength-of-wizards/description/

class Solution
{
public:
    long long sum_intervals(vector<long long> &pp, int l, int r)
    {
        return pp[r + 1] - pp[l + 1];
    }

    int totalStrength(vector<int> &strength)
    {
        long long MOD = 1000000007;
        const int N = strength.size();

        vector<long long> p(N + 1, 0L);
        for (int i = 0; i < N; ++i)
            p[i + 1] = (p[i] + strength[i]) % MOD;

        vector<long long> pp(N + 2, 0L);
        for (int i = 0; i < N + 1; ++i)
            pp[i + 1] = (pp[i] + p[i]) % MOD;

        vector<int> l(N, -1);
        // l[i] = first index x at the left and closest to i where strength[x] < strength[i]
        deque<int> ql;
        for (int i = 0; i < N; ++i)
        {
            while (!ql.empty() && strength[ql.back()] >= strength[i])
                ql.pop_back();
            l[i] = ql.empty() ? -1 : ql.back();
            ql.push_back(i);
        }

        vector<int> r(N, -1);
        // r[i] = first index y at the right and closest to i where strength[y] =< strength[i]
        deque<int> qr;
        for (int i = N - 1; i >= 0; --i)
        {
            while (!qr.empty() && strength[qr.back()] > strength[i])
                qr.pop_back();
            r[i] = qr.empty() ? N : qr.back();
            qr.push_back(i);
        }

        long long ans = 0L;
        for (int i = 0; i < N; ++i)
        {
            ans += 2 * MOD +
                   (sum_intervals(pp, i, r[i]) * (i - l[i]) % MOD -
                    sum_intervals(pp, l[i], i) * (r[i] - i) % MOD) %
                       MOD * strength[i] % MOD;
            ans %= MOD;
        }

        return ans;
    }
};