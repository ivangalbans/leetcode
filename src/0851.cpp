// https://leetcode.com/problems/loud-and-rich/description/

class Solution
{
public:
    void dfs(vector<int> g[500], int u, vector<bool> &visited, vector<int> &rtop_sort)
    {
        visited[u] = true;
        for (auto v : g[u])
            if (!visited[v])
                dfs(g, v, visited, rtop_sort);
        rtop_sort.push_back(u);
    }

    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
    {
        int n = quiet.size();
        vector<int> g[500];
        for (auto edge : richer)
            g[edge[0]].push_back(edge[1]);

        vector<int> rtop_sort;
        vector<bool> visited(n);
        for (int i = 0; i < n; ++i)
            if (!visited[i])
                dfs(g, i, visited, rtop_sort);

        vector<int> ans(n);
        vector<int> least_quiet(n);
        for (int i = 0; i < n; ++i)
        {
            ans[i] = i;
            least_quiet[i] = quiet[i];
        }

        for (int i = n - 1; i >= 0; --i)
        {
            int u = rtop_sort[i];
            for (auto v : g[u])
            {
                if (least_quiet[u] < least_quiet[v])
                {
                    least_quiet[v] = least_quiet[u];
                    ans[v] = ans[u];
                }
            }
        }

        return ans;
    }
};