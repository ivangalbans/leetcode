// https://leetcode.com/problems/queries-on-a-permutation-with-key/description/

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

    vector<int> processQueries(vector<int> &queries, int m)
    {
        int n = queries.size();
        vector<int> bit(m + n + 1);
        int index[m + 1];

        for (int i = 1; i <= m; ++i)
        {
            update(bit, n + i, 1);
            index[i] = n + i;
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
        {
            int pos = index[queries[i]];
            ans[i] = query(bit, pos - 1);
            int new_pos = n - i;
            update(bit, pos, -1);
            update(bit, new_pos, 1);
            index[queries[i]] = new_pos;
        }

        return ans;
    }
};