// https://leetcode.com/problems/number-of-provinces/description/

// Disjoint Set

struct disjoint_set
{
    vector<int> parent, count;

    disjoint_set(int n)
    {
        parent = vector<int>(n);
        count = vector<int>(n);

        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            count[i] = 1;
        }
    }

    int set_of(int x)
    {
        return x == parent[x] ? x : parent[x] = set_of(parent[x]);
    }

    void merge(int x, int y)
    {
        x = set_of(x);
        y = set_of(y);

        if (x == y)
            return;

        if (count[x] < count[y])
            swap(x, y);

        parent[y] = x;
        count[x] += count[y];
    }
};

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &m)
    {
        int n = m.size();
        disjoint_set ds(n);

        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (m[i][j])
                    ds.merge(i, j);

        int scc = 0;
        for (int i = 0; i < n; ++i)
            if (ds.set_of(i) == i)
                ++scc;

        return scc;
    }
};