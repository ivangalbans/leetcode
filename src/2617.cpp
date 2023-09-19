// https://leetcode.com/problems/minimum-number-of-visited-cells-in-a-grid/description/

// BFS

class Solution
{
public:
    int bfs(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<set<int>> rv(n), cv(m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                rv[i].insert(j), cv[j].insert(i);

        queue<vector<int>> q;
        q.push({0, 0, 1});
        while (!q.empty())
        {
            auto u = q.front();
            q.pop();
            int i = u[0], j = u[1], d = u[2];
            if (i == n - 1 && j == m - 1)
                return d;

            auto it = rv[i].lower_bound(j + 1);
            while (it != end(rv[i]) && *it <= j + grid[i][j])
            {
                q.push({i, *it, d + 1});
                cv[*it].erase(i);
                rv[i].erase(it++);
            }

            it = cv[j].lower_bound(i + 1);
            while (it != end(cv[j]) && *it <= i + grid[i][j])
            {
                q.push({*it, j, d + 1});
                rv[*it].erase(j);
                cv[j].erase(it++);
            }
        }

        return -1;
    }
    int minimumVisitedCells(vector<vector<int>> &grid)
    {

        return bfs(grid);
    }
};