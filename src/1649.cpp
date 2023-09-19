// https://leetcode.com/problems/create-sorted-array-through-instructions/description/

struct bit
{
    vector<int> ft;

    bit(int n) : ft(n + 1) {}

    int lowbit(int x)
    {
        return x & -x;
    }

    void update(int pos, int val)
    {
        for (; pos < ft.size(); pos += lowbit(pos))
            ft[pos] += val;
    }

    int query(int pos)
    {
        int sum = 0;
        for (; pos > 0; pos -= lowbit(pos))
            sum += ft[pos];
        return sum;
    }

    int query(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};

class Solution
{
public:
    const int MOD = 1000000000 + 7;
    const int N = 100000;
    int createSortedArray(vector<int> &instructions)
    {
        bit ft(N + 1);
        int ans = 0;
        for (auto num : instructions)
        {
            int lt = ft.query(1, num - 1);
            int gt = ft.query(num + 1, N);
            ft.update(num, 1);
            ans = (ans + min(lt, gt)) % MOD;
        }

        return ans;
    }
};