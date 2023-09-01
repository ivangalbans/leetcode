// https://leetcode.com/problems/count-number-of-rectangles-containing-each-point/description/

// Fenwick Tree

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
    vector<int> countRectangles(vector<vector<int>> &rectangles, vector<vector<int>> &points)
    {
        int n = rectangles.size();
        int m = points.size();
        const int H = 100;
        vector<int> idx(m), ans(m);

        iota(begin(idx), end(idx), 0);
        sort(begin(idx), end(idx), [&](int idx1, int idx2)
             { return points[idx1][0] > points[idx2][0]; });
        sort(begin(rectangles), end(rectangles), [](const auto &r1, const auto &r2)
             { return r1[0] > r2[0]; });

        bit ft(H + 1);
        for (int i = 0, j = 0; i < m; ++i)
        {
            while (j < n && rectangles[j][0] >= points[idx[i]][0])
                ft.update(rectangles[j++][1] + 1, 1);
            ans[idx[i]] = j - ft.query(points[idx[i]][1]);
        }

        return ans;
    }
};

// Binary Search O(100 * nlog(n))

class Solution
{
public:
    vector<int> countRectangles(vector<vector<int>> &rectangles, vector<vector<int>> &points)
    {
        int n = rectangles.size();
        int m = points.size();
        const int H = 100;

        vector<vector<int>> rect(H + 1);
        for (auto &r : rectangles)
            rect[r[1]].push_back(r[0]);
        for (auto &r : rect)
            sort(begin(r), end(r));

        vector<int> ans(m);
        int c;
        for (int i = 0; i < m; ++i)
        {
            c = 0;
            for (int y = points[i][1]; y <= H; ++y)
            {
                auto itr = lower_bound(begin(rect[y]), end(rect[y]), points[i][0]);
                c += distance(itr, end(rect[y]));
            }
            ans[i] = c;
        }

        return ans;
    }
};