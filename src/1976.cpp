// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

class Solution
{
public:
    const long long MOD = 1e9 + 7;
    const long long oo = 1e15;

    void dijkstra(vector<pair<long long, int>> g[200], int s, vector<pair<long long, long long>> &d)
    {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        d[s] = {0, 1};
        pq.push({0, s});
        while (!pq.empty())
        {
            auto [dist, u] = pq.top();
            pq.pop();
            if (dist == d[u].first)
            {
                for (auto [w, v] : g[u])
                {
                    if (d[u].first + w < d[v].first)
                    {
                        d[v] = {d[u].first + w, d[u].second};
                        pq.push({d[v].first, v});
                    }
                    else if (d[u].first + w == d[v].first)
                        d[v].second = (d[v].second + d[u].second) % MOD;
                }
            }
        }
    }
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<pair<long long, int>> g[200];
        for (auto e : roads)
        {
            g[e[0]].push_back({e[2], e[1]});
            g[e[1]].push_back({e[2], e[0]});
        }

        // <min_d, n_ways>
        vector<pair<long long, long long>> d(n, {oo, 0});
        dijkstra(g, 0, d);

        return d[n - 1].second;
    }
};

// Floyd Warshall

class Solution
{
public:
    const long long oo = 1e15;
    const long long MOD = 1e9 + 7;

    void floyd_warshall(int n, vector<vector<long long>> &d, vector<vector<long long>> &w)
    {
        for (int i = 0; i < n; ++i)
        {
            d[i][i] = 0;
            w[i][i] = 1;
        }

        for (int k = 0; k < n; ++k)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (i != k && j != k)
                    {
                        if (d[i][k] + d[k][j] == d[i][j])
                        {
                            w[i][j] = (w[i][j] + w[i][k] * w[k][j]) % MOD;
                        }
                        if (d[i][k] + d[k][j] < d[i][j])
                        {
                            w[i][j] = (w[i][k] * w[k][j]) % MOD;
                            d[i][j] = d[i][k] + d[k][j];
                        }
                    }
                }
            }
        }
    }

    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<vector<long long>> d(n, vector<long long>(n, oo));
        vector<vector<long long>> w(n, vector<long long>(n));

        for (auto e : roads)
        {
            d[e[0]][e[1]] = e[2];
            d[e[1]][e[0]] = e[2];
            w[e[0]][e[1]] = 1;
            w[e[1]][e[0]] = 1;
        }

        floyd_warshall(n, d, w);
        return w[0][n - 1];
    }
};