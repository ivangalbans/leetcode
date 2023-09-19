// https://leetcode.com/problems/queue-reconstruction-by-height/

// Insertion O(n^2)

class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(begin(people), end(people), [](auto p1, auto p2)
             { return pair<int, int>(-p1[0], p1[1]) < pair<int, int>(-p2[0], p2[1]); });
        vector<vector<int>> ans;
        for (auto p : people)
            ans.insert(begin(ans) + p[1], p);

        return ans;
    }
};

// Fenwick Tree O(n*log^2(n))
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
};

class Solution
{
public:
    int findPos(bit &ft, int n, int k)
    {
        int lo = 1, hi = n;
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if (mid - ft.query(mid) < k + 1)
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo - 1;
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        int n = people.size();
        sort(begin(people), end(people), [](auto p1, auto p2)
             { return make_pair(p1[0], -p1[1]) < make_pair(p2[0], -p2[1]); });

        bit ft(n);
        vector<vector<int>> ans(n, vector<int>(2, -1));
        for (auto p : people)
        {
            int pos = findPos(ft, n, p[1]);
            ft.update(pos + 1, 1);
            ans[pos] = p;
        }

        return ans;
    }
};