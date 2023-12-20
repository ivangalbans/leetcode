// https://leetcode.com/problems/course-schedule-ii/

class Solution
{
public:
    enum Color
    {
        WHITE,
        GRAY,
        BLACK
    };

    bool dfs(vector<int> g[2000], int u, vector<Color> &colors, vector<int> &tps)
    {
        colors[u] = GRAY;

        for (auto v : g[u])
        {
            if (colors[v] == WHITE && !dfs(g, v, colors, tps))
                return false;
            else if (colors[v] == GRAY)
                return false;
        }

        tps.push_back(u);
        colors[u] = BLACK;
        return true;
    }

    vector<int> findOrder(int n, vector<vector<int>> &edges)
    {
        vector<int> g[2000];
        for (auto edge : edges)
            g[edge[1]].push_back(edge[0]);

        vector<int> tps;
        vector<Color> colors(n, WHITE);
        for (int i = 0; i < n; ++i)
            if (colors[i] == WHITE && !dfs(g, i, colors, tps))
                return {};

        reverse(begin(tps), end(tps));
        return tps;
    }
};