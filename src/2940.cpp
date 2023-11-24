// https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/description/

class Solution
{
public:
    bool cmp_point(auto &v1, auto &v2)
    {
        return v1[1] != v2[1] ? v1[1] > v2[1] : v1[0] > v2[0];
    }

    int search(vector<int> &a, deque<int> &idx, int i, int j)
    {
        if (i == j || a[i] < a[j])
            return j;

        auto it = upper_bound(idx.begin(), idx.end(), i, [&](int x, int y)
                              { return a[x] < a[y]; });

        return it == idx.end() ? -1 : *it;
    }

    vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries)
    {
        int n = heights.size();
        int q = queries.size();
        vector<int> idx(q);
        iota(begin(idx), end(idx), 0);

        for (auto &v : queries)
            if (v[0] > v[1])
                swap(v[0], v[1]);

        sort(begin(idx), end(idx), [&](int x, int y)
             { return cmp_point(queries[x], queries[y]); });

        vector<int> ans(q);
        int i = n - 1;
        deque<int> dq;
        for (auto id : idx)
        {
            int x = queries[id][0], y = queries[id][1];
            while (i >= y)
            {
                while (!dq.empty() && heights[i] >= heights[dq.front()])
                    dq.pop_front();
                dq.push_front(i--);
            }
            ans[id] = search(heights, dq, x, y);
        }

        return ans;
    }
};