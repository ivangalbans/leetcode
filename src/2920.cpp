// https://leetcode.com/problems/maximum-points-after-collecting-coins-from-all-nodes/

class Solution
{
public:
    bool visited[100001][14] = {};
    int dfs(int u, int parent, vector<vector<int>> &g, vector<int> &coins, int k, int div)
    {
        if (div > 13 || visited[u][div])
            return 0;

        int way1 = (coins[u] >> div) - k;
        int way2 = coins[u] >> (div + 1);
        visited[u][div] = true;
        for (auto v : g[u])
        {
            if (v != parent)
            {
                way1 += dfs(v, u, g, coins, k, div);
                way2 += dfs(v, u, g, coins, k, div + 1);
            }
        }

        return max(way1, way2);
    }
    int maximumPoints(vector<vector<int>> &edges, vector<int> &coins, int k)
    {
        int n = coins.size();
        vector<vector<int>> g(n);
        for (auto edge : edges)
        {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        return dfs(0, -1, g, coins, k, 0);
    }
};