// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/

// DFS

class Solution
{
public:
    int dfs(vector<int> g[100001], int u, vector<bool> &visited)
    {
        visited[u] = true;

        int children = 0;
        for (auto v : g[u])
            if (!visited[v])
                children += dfs(g, v, visited);

        return 1 + children;
    }

    long long countPairs(int n, vector<vector<int>> &edges)
    {
        vector<int> g[100001];
        for (auto e : edges)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<int> scc;
        vector<bool> visited(n);
        for (int i = 0; i < n; ++i)
            if (!visited[i])
                scc.push_back(dfs(g, i, visited));

        int total = accumulate(begin(scc), end(scc), 0);
        long long ans = 0;
        for (long long c : scc)
            ans += (c * (total - c));

        return ans / 2;
    }
};

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
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        disjoint_set ds(n);
        for (auto edge : edges)
            ds.merge(edge[0], edge[1]);

        vector<long long> groups(n);
        for (int i = 0; i < n; ++i)
        {
            int set_of = ds.set_of(i);
            groups[set_of] = ds.count[set_of];
        }

        long long total = accumulate(begin(groups), end(groups), 0);
        long long ans = 0;
        for (auto cnt : groups)
            ans += cnt * (total - cnt);

        return ans / 2;
    }
};