// https://leetcode.com/problems/find-if-path-exists-in-graph/

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
    bool validPath(int n, vector<vector<int>> &edges, int src, int dst)
    {
        disjoint_set ds(n);
        for (auto edge : edges)
            ds.merge(edge[0], edge[1]);
        return ds.set_of(src) == ds.set_of(dst);
    }
};

// DFS

class Solution
{
public:
    void dfs(vector<int> g[200001], int u, vector<bool> &visited)
    {
        visited[u] = true;
        for (auto v : g[u])
            if (!visited[v])
                dfs(g, v, visited);
    }

    bool validPath(int n, vector<vector<int>> &edges, int src, int dst)
    {
        vector<int> g[200001];
        for (auto e : edges)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n);
        dfs(g, src, visited);

        return visited[dst];
    }
};
