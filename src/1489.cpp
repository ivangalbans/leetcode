// https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/description/

struct disjoint_set
{
    int n;
    vector<int> parent, count;
    disjoint_set(int n) : n(n)
    {
        parent = vector<int>(n);
        count = vector<int>(n);
        reset();
    }

    int set_of(int x)
    {
        return x == parent[x] ? x : parent[x] = set_of(parent[x]);
    }

    void merge(int x, int y)
    {
        x = set_of(x);
        y = set_of(y);

        if (count[x] < count[y])
            swap(x, y);

        parent[y] = x;
        count[x] += count[y];
    }

    void reset()
    {
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            count[i] = 1;
        }
    }
};

class Solution
{
public:
    static bool cmp(const vector<int> &e1, const vector<int> &e2)
    {
        return e1[2] < e2[2];
    }

    int kruskal(int n, vector<vector<int>> &edges, disjoint_set &ds, pair<int, int> skip)
    {
        int cost = 0;
        for (auto e : edges)
        {
            int u = e[0], v = e[1], w = e[2];
            if (u == skip.first && v == skip.second)
                continue;
            if (ds.set_of(u) != ds.set_of(v))
            {
                ds.merge(u, v);
                cost += w;
            }
        }

        if (skip.first != -1)
            for (int i = 0; i < n; ++i)
                if (ds.set_of(i) != ds.set_of(0))
                    return 1e9;

        return cost;
    }

    int kruskal(int n, vector<vector<int>> &edges, disjoint_set &ds)
    {
        return kruskal(n, edges, ds, {-1, -1});
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> sorted_edges(begin(edges), end(edges));
        sort(begin(sorted_edges), end(sorted_edges), cmp);

        disjoint_set ds(n);
        int mst_cost = kruskal(n, sorted_edges, ds);
        cout << mst_cost << endl;

        vector<vector<int>> ans(2);
        for (int i = 0; i < edges.size(); ++i)
        {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            ds.reset();
            if (kruskal(n, sorted_edges, ds, {u, v}) > mst_cost)
                ans[0].push_back(i);
            else
            {
                ds.reset();
                ds.merge(u, v);
                if (kruskal(n, sorted_edges, ds) + w == mst_cost)
                    ans[1].push_back(i);
            }
        }

        return ans;
    }
};