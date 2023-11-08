// https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/description/

// Backtracking

class Solution
{
private:
    int ans;
    void dfs(int n, int m, vector<int> &h, int cnt)
    {
        if (count(begin(h), end(h), n) == m)
        {
            ans = min(ans, cnt);
            return;
        }

        if (cnt >= ans)
            return;

        int l = min_element(begin(h), end(h)) - begin(h);
        int min_h = h[l];
        int r = l + 1;
        while (r < m && h[r] == min_h)
            ++r;

        for (int i = min(r - l, n - min_h); i >= 1; --i)
        {
            vector<int> new_h(begin(h), end(h));
            for (int j = 0; j < i; ++j)
                new_h[l + j] += i;
            dfs(n, m, new_h, cnt + 1);
        }
    }

public:
    int tilingRectangle(int n, int m)
    {
        ans = n * m;
        vector<int> heights(m);
        dfs(n, m, heights, 0);
        return ans;
    }
};
