//

class Solution
{
public:
    int N;

    bool inside(int i, int j)
    {
        return i >= 0 && i < N && j >= 0 && j < N;
    }

    vector<pair<int, int>> adj(int i, int j)
    {
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        vector<pair<int, int>> adj_pos;
        for (int k = 0; k < 4; ++k)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            if (inside(x, y))
                adj_pos.push_back({x, y});
        }

        return adj_pos;
    }

    int bfs(vector<vector<int>> &grid, pair<int, int> origin, int id)
    {
        queue<pair<int, int>> q;
        int cnt = 1;

        grid[origin.first][origin.second] = id;
        q.push(origin);
        while (!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();
            for (auto [x, y] : adj(i, j))
            {
                if (grid[x][y] == 1)
                {
                    grid[x][y] = id;
                    ++cnt;
                    q.push({x, y});
                }
            }
        }

        return cnt;
    }

    int largestIsland(vector<vector<int>> &grid)
    {
        N = grid.size();
        unordered_map<int, int> cnt;
        int ans = 0;
        int id = -1;

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (grid[i][j] == 1)
                {
                    cnt[id] = bfs(grid, {i, j}, id);
                    ans = max(ans, cnt[id--]);
                }
            }
        }

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (grid[i][j] == 0)
                {
                    unordered_map<int, bool> used;
                    int temp = 0;
                    for (auto [x, y] : adj(i, j))
                    {
                        if (grid[x][y] != 0 && !used[grid[x][y]])
                        {
                            temp += cnt[grid[x][y]];
                            used[grid[x][y]] = true;
                        }
                    }
                    ans = max(ans, 1 + temp);
                }
            }
        }

        return ans;
    }
};