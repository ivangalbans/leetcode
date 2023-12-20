// https://leetcode.com/problems/find-the-safest-path-in-a-grid/

class Solution
{
public:
    const int oo = 1e6;
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};

    bool inside(int i, int j, int n)
    {
        return i >= 0 && i < n && j >= 0 && j < n;
    }

    void compute_sf(vector<vector<int>> &grid, int n, vector<vector<int>> &sf)
    {
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j])
                {
                    q.push({i, j});
                    sf[i][j] = 0;
                }
            }
        }

        while (!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();
            for (int dir = 0; dir < 4; ++dir)
            {
                int x = i + dx[dir];
                int y = j + dy[dir];
                if (inside(x, y, n) && sf[x][y] == oo)
                {
                    sf[x][y] = sf[i][j] + 1;
                    q.push({x, y});
                }
            }
        }
    }

    bool exist_path(vector<vector<int>> &sf, int n, int k, bool visited[][400])
    {
        queue<pair<int, int>> q;

        if (sf[0][0] >= k)
        {
            visited[0][0] = true;
            q.push({0, 0});
        }
        while (!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();

            if (i == n - 1 && j == n - 1)
                return true;

            for (int dir = 0; dir < 4; ++dir)
            {
                int x = i + dx[dir];
                int y = j + dy[dir];
                if (inside(x, y, n) && !visited[x][y] && sf[x][y] >= k)
                {
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        int n = grid.size();

        vector<vector<int>> sf(n, vector<int>(n, oo));
        compute_sf(grid, n, sf);

        bool visited[400][400];
        int lo = 0, hi = n * n;
        while (lo <= hi)
        {
            memset(visited, false, sizeof(visited));
            int mid = (lo + hi) / 2;
            if (exist_path(sf, n, mid, visited))
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        return lo - 1;
    }
};