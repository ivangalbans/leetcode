// https://leetcode.com/problems/maximum-score-after-applying-operations-on-a-tree/

class Solution
{
public:
    // <sum, answer>
    pair<long long, long long> dfs(vector<vector<int>> &g, int u, int parent, vector<int> &values)
    {
        long long sum = 0, max_score = -values[u];
        for (auto v : g[u])
        {
            if (v != parent)
            {
                auto [sum_v, max_score_v] = dfs(g, v, u, values);
                sum += sum_v;
                max_score = max(0LL, max_score) + max_score_v;
            }
        }

        return {values[u] + sum, max(sum, values[u] + max_score)};
    }

    long long maximumScoreAfterOperations(vector<vector<int>> &edges, vector<int> &values)
    {
        vector<vector<int>> g(values.size(), vector<int>());
        for (auto edge : edges)
        {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        return dfs(g, 0, -1, values).second;
    }
};