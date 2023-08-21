// No clean solution: just wanted to test the Fenwick Tree
// https://leetcode.com/problems/count-number-of-teams/description/

class Solution
{
public:
    int lowbit(int x)
    {
        return x & -x;
    }

    void update(vector<int> &bit, int pos, int val)
    {
        for (; pos < bit.size(); pos += lowbit(pos))
            bit[pos] += val;
    }

    int query(vector<int> &bit, int pos)
    {
        int sum = 0;
        for (; pos > 0; pos -= lowbit(pos))
            sum += bit[pos];
        return sum;
    }

    int query(vector<int> &bit, int l, int r)
    {
        return l == 0 ? query(bit, r) : query(bit, r) - query(bit, l - 1);
    }

    int numTeams2(vector<int> &rating)
    {
        int n = rating.size();
        int N = 100000;
        vector<int> le(n), gt(n);
        vector<int> bit1(N + 2), bit2(N + 2);

        for (int i = 0; i < n; ++i)
        {
            le[i] = query(bit1, 1, rating[i] - 1);
            update(bit1, rating[i], 1);
        }

        for (int i = n - 1; i >= 0; --i)
        {
            update(bit2, rating[i], 1);
            gt[i] = query(bit2, rating[i] + 1, N);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans += le[i] * gt[i];

        return ans;
    }

    int numTeams(vector<int> &rating)
    {
        int A = numTeams2(rating);
        reverse(begin(rating), end(rating));
        int B = numTeams2(rating);
        return A + B;
    }
};