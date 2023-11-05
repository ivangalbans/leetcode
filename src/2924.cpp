// https://leetcode.com/problems/find-champion-ii/

class Solution
{
public:
    int visited[101] = {0};

    void dfs(vector<vector<int>> &g, int u)
    {
        visited[u] = true;
        for (auto v : g[u])
            if (!visited[v])
                dfs(g, v);
    }

    int findChampion(int n, vector<vector<int>> &edges)
    {
        vector<int> inDeg(n);
        vector<vector<int>> g(101, vector<int>());
        for (auto edge : edges)
        {
            inDeg[edge[1]]++;
            g[edge[0]].push_back(edge[1]);
        }

        int root = -1;
        for (int i = 0; i < n; ++i)
        {
            if (inDeg[i] == 0)
            {
                root = i;
                break;
            }
        }

        if (root == -1)
            return -1;

        dfs(g, root);

        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
                return -1;
        }

        return root;
    }
};