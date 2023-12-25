// https://leetcode.com/problems/minimum-cost-to-convert-string-i/

class Solution
{
public:
    const long long oo = 1e15;

    void floyd_warshall(int n, vector<vector<long long>> &d)
    {
        for (int i = 0; i < n; ++i)
            d[i][i] = 0;
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    };

    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        long long ans = 0;
        vector<vector<long long>> d(26, vector<long long>(26, oo));
        for (int i = 0; i < original.size(); ++i)
        {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            long long w = cost[i];
            d[u][v] = min(d[u][v], w);
        }

        floyd_warshall(26, d);

        for (int i = 0; i < source.length(); ++i)
        {
            if (source[i] != target[i])
            {
                long long path_cost = d[source[i] - 'a'][target[i] - 'a'];
                if (path_cost == oo)
                    return -1;
                ans += path_cost;
            }
        }
        return ans;
    }
};