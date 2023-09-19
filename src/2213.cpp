// https://leetcode.com/problems/longest-substring-of-one-repeating-character/description/

#define left(x) ((x << 1) + 1)
#define right(x) ((x << 1) + 2)

struct node
{
    int size;
    int lchar, rchar;
    int prefix, suffix;
    int longest;

    int merge(node &l, node &r)
    {
        size = l.size + r.size;
        lchar = l.lchar;
        rchar = r.rchar;
        prefix = l.prefix + (l.prefix == l.size && l.rchar == r.lchar ? r.prefix : 0);
        suffix = r.suffix + (r.suffix == r.size && l.rchar == r.lchar ? l.suffix : 0);
        return longest = max(max(l.longest, r.longest),
                             (l.rchar == r.lchar ? l.suffix + r.prefix : 0));
    }
};

struct segment_tree
{
    vector<node> st;
    int n;

    segment_tree(int n) : n(n), st(4 * n) {}

    int update(int node, int nodeL, int nodeR, int pos, char c)
    {
        if (nodeL == nodeR)
        {
            st[node].lchar = st[node].rchar = c;
            return st[node].size = st[node].prefix = st[node].suffix = st[node].longest = 1;
        }

        int nodeM = (nodeL + nodeR) / 2;
        if (pos <= nodeM)
            update(left(node), nodeL, nodeM, pos, c);
        else
            update(right(node), nodeM + 1, nodeR, pos, c);
        return st[node].merge(st[left(node)], st[right(node)]);
    }
};

class Solution
{
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int> &queryIndices)
    {
        int n = s.length();
        int q = queryIndices.size();
        segment_tree st(n);
        vector<int> ans(q);

        for (int i = 0; i < n; ++i)
            st.update(0, 0, n - 1, i, s[i]);
        for (int i = 0; i < q; ++i)
            ans[i] = st.update(0, 0, n - 1, queryIndices[i], queryCharacters[i]);

        return ans;
    }
};