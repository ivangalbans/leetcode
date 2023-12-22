// https://leetcode.com/problems/path-with-maximum-probability/description/

class Solution
{
public:
    bool equal(double a, double b)
    {
        return abs(a - b) < 1e-5;
    }

    void dijkstra(vector<pair<double, int>> g[10000], int n, int s, vector<double> &d)
    {
        priority_queue<pair<double, int>> pq;

        d[s] = 1;
        pq.push({1, s});
        while (!pq.empty())
        {
            auto [prob, u] = pq.top();
            pq.pop();
            if (equal(prob, d[u]))
            {
                for (auto [p, v] : g[u])
                {
                    if (d[u] * p > d[v])
                    {
                        d[v] = d[u] * p;
                        pq.push({d[v], v});
                    }
                }
            }
        }
    }

    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
    {
        vector<pair<double, int>> g[10000];
        for (int i = 0; i < edges.size(); ++i)
        {
            g[edges[i][0]].push_back({succProb[i], edges[i][1]});
            g[edges[i][1]].push_back({succProb[i], edges[i][0]});
        }

        vector<double> d(n);
        dijkstra(g, n, start_node, d);

        return d[end_node];
    }
};