// https://leetcode.com/problems/minimum-cost-to-convert-string-ii/description/

class Solution
{
public:
    const long long oo = 1e15;

    unordered_map<string, unordered_map<string, long long>> memo;
    long long d[200][200];

    void floyd_warshall(int n)
    {
        for (int i = 0; i < n; ++i)
            d[i][i] = 0;
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    };

    long long minimumCost(string source, string target, vector<string> &original, vector<string> &changed, vector<int> &cost)
    {
        unordered_map<string, int> rank;
        set<int> lens;
        int n = 0;
        for (auto s : original)
            if (rank.count(s) == 0)
                rank[s] = n++, lens.insert(s.length());

        for (auto s : changed)
            if (rank.count(s) == 0)
                rank[s] = n++, lens.insert(s.length());

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = oo;
        for (int i = 0; i < original.size(); ++i)
        {
            int u = rank[original[i]];
            int v = rank[changed[i]];
            long long w = cost[i];
            d[u][v] = min(d[u][v], w);
        }
        floyd_warshall(n);

        vector<long long> dp(source.length() + 1, oo);
        dp[0] = 0;
        for (int i = 1; i <= source.length(); ++i)
        {
            if (source[i - 1] == target[i - 1])
                dp[i] = dp[i - 1];
            for (auto len : lens)
            {
                if (i - len < 0)
                    break;
                string src = source.substr(i - len, len);
                string tar = target.substr(i - len, len);
                if (rank.count(src) && rank.count(tar))
                {
                    dp[i] = min(dp[i], dp[i - len] + d[rank[src]][rank[tar]]);
                }
            }
        }

        return dp[source.length()] == oo ? -1 : dp[source.length()];
    }
};