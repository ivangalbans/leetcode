// https://leetcode.com/problems/count-the-number-of-houses-at-a-certain-distance-i/description/

// Floyd Wharshall O(N^3)

class Solution
{
public:
    vector<int> countOfPairs(int n, int x, int y)
    {
        const int oo = 1000000;
        x--;
        y--;
        vector<vector<int>> d(n, vector<int>(n, oo));
        for (int i = 0; i + 1 < n; ++i)
            d[i][i + 1] = d[i + 1][i] = 1;
        for (int i = 0; i < n; ++i)
            d[i][i] = 0;
        if (x != y)
            d[x][y] = d[y][x] = 1;

        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

        vector<int> ans(n);
        for (int k = 1; k <= n; ++k)
        {
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (d[i][j] == k)
                        ans[k - 1]++;
        }

        return ans;
    }
};