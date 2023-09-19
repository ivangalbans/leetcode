// https://leetcode.com/problems/longest-increasing-subsequence-ii/description/

// DP with Segment Tree

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
            st[node] = val;
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
    const int N = 100000;
    int lengthOfLIS(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> dp(N + 1);
        segment_tree st(N + 1);

        for (auto a : nums)
        {
            dp[a] = max(dp[a], 1 + st.query(max(0, a - k), a - 1));
            st.update(a, dp[a]);
        }

        return *max_element(begin(dp), end(dp));
    }
};