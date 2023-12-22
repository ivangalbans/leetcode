// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

// Bellman-Ford

class Solution
{
public:
    const int oo = 1e9;

    void bellman_ford(int n, vector<vector<int>> &edges, int s, int k, vector<vector<int>> &d)
    {
        d[s][0] = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            for (auto e : edges)
            {
                int u = e[0], v = e[1], w = e[2];
                for (int j = 0; j < k; ++j)
                    if (d[u][j] + w < d[v][j + 1])
                        d[v][j + 1] = d[u][j] + w;
            }
        }
    }

    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        ++k; // include destination
        // d[i][k] = distance from src with exactly k stops
        vector<vector<int>> d(n, vector<int>(k + 1, oo));
        bellman_ford(n, flights, src, k, d);

        int min_d = *min_element(begin(d[dst]), end(d[dst]));
        return min_d == oo ? -1 : min_d;
    }
};

// Dijkstra

class Solution
{
public:
    const int oo = 1e9;

    void dijkstra(vector<pair<int, int>> g[100], int n, int s, int stops, vector<vector<int>> &d)
    {
        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
        d[s][0] = 0;
        pq.push({{0, 0}, s});
        while (!pq.empty())
        {
            auto [dist_stops, u] = pq.top();
            pq.pop();
            auto [dist, k] = dist_stops;
            if (dist == d[u][k])
            {
                for (auto [w, v] : g[u])
                {
                    if (k < stops && d[u][k] + w < d[v][k + 1])
                    {
                        d[v][k + 1] = d[u][k] + w;
                        pq.push({{d[v][k + 1], k + 1}, v});
                    }
                }
            }
        }
    }

    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<pair<int, int>> g[100];
        for (auto e : flights)
            g[e[0]].push_back({e[2], e[1]});

        ++k; // include destination
        // d[i][k] = distance from src with exactly k stops
        vector<vector<int>> d(n, vector<int>(k + 1, oo));
        dijkstra(g, n, src, k, d);

        int min_d = *min_element(begin(d[dst]), end(d[dst]));
        return min_d == oo ? -1 : min_d;
    }
};