// https://leetcode.com/problems/maximum-sum-queries/description/

#define left(x) ((x << 1) + 1)
#define right(x) ((x << 1) + 2)

struct segment_tree
{
    vector<int> st;
    int n;
    segment_tree(int n) : n(n), st(4 * n) {}

    void update(int node, int nodeL, int nodeR, int pos, int val)
    {
        if (nodeL == nodeR)
        {
            st[node] = max(st[node], val);
            return;
        }

        int nodeM = (nodeL + nodeR) / 2;

        if (pos <= nodeM)
            update(left(node), nodeL, nodeM, pos, val);
        else
            update(right(node), nodeM + 1, nodeR, pos, val);
        st[node] = max(st[left(node)], st[right(node)]);
    }

    void update(int pos, int val)
    {
        update(0, 0, n - 1, pos, val);
    }

    int query(int node, int nodeL, int nodeR, int left, int right)
    {
        if (nodeL == left && nodeR == right)
            return st[node];

        int nodeM = (nodeL + nodeR) / 2;

        if (right <= nodeM)
            return query(left(node), nodeL, nodeM, left, right);
        if (left > nodeM)
            return query(right(node), nodeM + 1, nodeR, left, right);
        return max(query(left(node), nodeL, nodeM, left, nodeM),
                   query(right(node), nodeM + 1, nodeR, nodeM + 1, right));
    }

    int query(int left, int right)
    {
        return query(0, 0, n - 1, left, right);
    }
};

class Solution
{
public:
    vector<int> maximumSumQueries(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &queries)
    {
        int n = nums1.size(), m = queries.size();
        vector<pair<int, int>> v(n), q(m);
        for (int i = 0; i < n; ++i)
            v[i] = {nums1[i], nums2[i]};
        for (int i = 0; i < m; ++i)
            q[i] = {queries[i][0], queries[i][1]};
        vector<int> idq(m);
        iota(begin(idq), end(idq), 0);
        sort(begin(idq), end(idq), [&](int id1, int id2)
             { return q[id1] > q[id2]; });
        sort(begin(v), end(v), [&](auto p1, auto p2)
             { return p1 > p2; });

        set<int> compress;
        int len = 0;
        unordered_map<int, int> rank;
        for (auto x : v)
            compress.insert(x.second);
        for (auto x : q)
            compress.insert(x.second);
        for (auto x : compress)
            rank[x] = ++len;

        segment_tree st(len + 1);
        vector<int> ans(m);
        for (int i = 0, j = 0; i < m; ++i)
        {
            int qx = q[idq[i]].first, qy = q[idq[i]].second;
            while (j < n && v[j].first >= qx)
            {
                st.update(rank[v[j].second], v[j].first + v[j].second);
                ++j;
            }
            int sum = st.query(rank[qy], len);
            ans[idq[i]] = sum == 0 ? -1 : sum;
        }

        return ans;
    }
};