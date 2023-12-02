// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/

// DFS

class Solution
{
public:
    long long dfs(vector<vector<int>> &g, int u, vector<bool> &visited)
    {
        visited[u] = true;

        int cnt = 0;
        for (auto v : g[u])
            if (!visited[v])
                cnt += dfs(g, v, visited);

        return 1 + cnt;
    }

    long long countPairs(int n, vector<vector<int>> &edges)
    {
        vector<bool> visited(n);

        vector<vector<int>> g(n);
        for (auto e : edges)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<long long> comp;
        long long sum = 0;
        for (int i = 0; i < n; ++i)
            if (!visited[i])
            {
                long long cnt = dfs(g, i, visited);
                sum += cnt;
                comp.push_back(cnt);
            }

        long long ans = 0;
        for (auto x : comp)
            ans += x * (sum - x);

        return ans / 2;
    }
};

// Disjoint Set