// https://leetcode.com/problems/network-delay-time/description/

// Bellman-Ford

class Solution
{
public:
    const int oo = 1e9;

    void bellman_ford(int n, vector<vector<int>> &edges, int s, vector<int> &d)
    {
        d[s] = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            for (auto e : edges)
            {
                int u = e[0] - 1, v = e[1] - 1, w = e[2];
                if (d[u] + w < d[v])
                    d[v] = d[u] + w;
            }
        }
    }

    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<int> d(n, oo);
        bellman_ford(n, times, k - 1, d);
        int max_d = *max_element(begin(d), end(d));
        return max_d == oo ? -1 : max_d;
    }
};

// Dijkstra

class Solution
{
public:
    const int oo = 1e9;

    void dijkstra(vector<pair<int, int>> g[100], int s, vector<int> &d)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        d[s] = 0;
        pq.push({0, s});
        while (!pq.empty())
        {
            auto [dist, u] = pq.top();
            pq.pop();
            if (dist == d[u])
            {
                for (auto [w, v] : g[u])
                {
                    if (d[u] + w < d[v])
                    {
                        d[v] = d[u] + w;
                        pq.push({d[v], v});
                    }
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<pair<int, int>> g[100];
        for (auto e : times)
            g[e[0] - 1].push_back({e[2], e[1] - 1});

        vector<int> d(n, oo);
        dijkstra(g, k - 1, d);

        int max_d = *max_element(begin(d), end(d));
        return max_d == oo ? -1 : max_d;
    }
};

// Floyd-Warshall

class Solution
{
public:
    const int oo = 1e9;

    void floyd_warshall(int n, vector<vector<int>> &d)
    {
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }

    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<int>> d(n, vector<int>(n, oo));
        for (auto e : times)
            d[e[0] - 1][e[1] - 1] = e[2];

        for (int i = 0; i < n; ++i)
            d[i][i] = 0;

        floyd_warshall(n, d);
        int best = *max_element(begin(d[k - 1]), end(d[k - 1]));
        return best == oo ? -1 : best;
    }
};