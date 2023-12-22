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