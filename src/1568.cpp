// https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/description/

class Solution
{
public:
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};
    int m, n;

    vector<int> low, d, pi;
    vector<bool> articulation_points;
    int time;
    int root_children;

    int one_dim(int i, int j)
    {
        return i * n + j;
    }

    bool inside(int i, int j, int m, int n)
    {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    void dfs(vector<int> g[900], int root, int u)
    {
        low[u] = d[u] = ++time;
        for (auto v : g[u])
        {
            if (d[v] == 0)
            {
                pi[v] = u;
                if (u == root)
                    root_children++;

                dfs(g, root, v);

                if (low[v] >= d[u])
                    articulation_points[u] = true;

                low[u] = min(low[u], low[v]);
            }
            else if (v != pi[u])
                low[u] = min(low[u], d[v]);
        }
    }

    int minDays(vector<vector<int>> &grid)
    {
        m = grid.size(), n = grid[0].size();

        vector<int> g[900];
        int cnt = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j])
                {
                    cnt++;
                    for (int k = 0; k < 4; ++k)
                    {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (inside(x, y, m, n) && grid[x][y])
                            g[one_dim(i, j)].push_back(one_dim(x, y));
                    }
                }
            }
        }

        low = vector<int>(n * m);
        d = vector<int>(n * m);
        pi = vector<int>(n * m);
        articulation_points = vector<bool>(m * n);
        time = 0;
        int islands = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] && !d[one_dim(i, j)])
                {
                    dfs(g, one_dim(i, j), one_dim(i, j));
                    articulation_points[one_dim(i, j)] = (root_children >= 2);
                    islands++;
                }
            }
        }

        bool exist_ap = count(begin(articulation_points), end(articulation_points), true) > 0;

        return (cnt == 0 || islands >= 2) ? 0 : ((cnt == 1 || exist_ap) ? 1 : 2);
    }
};