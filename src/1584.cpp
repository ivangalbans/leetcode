// https://leetcode.com/problems/min-cost-to-connect-all-points/

// Kruskal

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

struct Edge
{
    int src, dst, weight;

    Edge(int src, int dst, int weight) : src(src), dst(dst), weight(weight) {}

    bool operator<(const Edge &e) const
    {
        return weight < e.weight;
    }
};

class Solution
{
public:
    int manhattan_distance(vector<int> &p1, vector<int> &p2)
    {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }

    int kruskal(int nodes, vector<Edge> &edges)
    {
        sort(begin(edges), end(edges));
        int cost = 0;

        disjoint_set ds(nodes);
        for (auto e : edges)
        {
            if (ds.set_of(e.src) != ds.set_of(e.dst))
            {
                ds.merge(e.src, e.dst);
                cost += e.weight;
            }
        }

        return cost;
    }

    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();

        vector<Edge> edges;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int d = manhattan_distance(points[i], points[j]);
                edges.push_back(Edge(i, j, d));
                edges.push_back(Edge(j, i, d));
            }
        }

        return kruskal(n, edges);
    }
};

// Prim

typedef pair<int, pair<int, int>> edge;

class Solution
{
public:
    int manhattan_distance(vector<int> &p1, vector<int> &p2)
    {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }

    void process(vector<pair<int, int>> g[1000], int u, vector<bool> &visited, priority_queue<edge, vector<edge>, greater<edge>> &pq)
    {
        visited[u] = true;
        for (auto [w, v] : g[u])
            if (!visited[v])
                pq.push({w, {u, v}});
    }

    int prim(vector<pair<int, int>> g[1000], int n)
    {
        vector<bool> visited(n);
        priority_queue<edge, vector<edge>, greater<edge>> pq;

        process(g, 0, visited, pq);

        int cost = 0;
        while (!pq.empty())
        {
            auto [w, nodes] = pq.top();
            pq.pop();
            auto [u, v] = nodes;
            if (!visited[v])
            {
                process(g, v, visited, pq);
                cost += w;
            }
        }

        return cost;
    }

    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();

        vector<pair<int, int>> g[1000];
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int d = manhattan_distance(points[i], points[j]);
                g[i].push_back({d, j});
                g[j].push_back({d, i});
            }
        }

        return prim(g, n);
    }
};