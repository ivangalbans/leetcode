// https://leetcode.com/problems/smallest-string-with-swaps/description/

// DFS

class Solution
{

public:
    void dfs(string &s, vector<int> g[100001], vector<int> &visited, int u, vector<int> &group_id, vector<char> &group_val)
    {
        visited[u] = true;
        group_id.push_back(u);
        group_val.push_back(s[u]);
        for (auto v : g[u])
            if (!visited[v])
                dfs(s, g, visited, v, group_id, group_val);
    }

    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        int n = s.length();
        vector<int> g[100001];
        vector<int> visited(100001);
        for (auto edge : pairs)
        {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        vector<vector<int>> group_id(n);
        vector<vector<char>> group_val(n);
        int scc = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                dfs(s, g, visited, i, group_id[scc], group_val[scc]);
                scc++;
            }
        }

        string ans = s;
        for (int i = 0; i < scc; ++i)
        {
            sort(begin(group_id[i]), end(group_id[i]));
            sort(begin(group_val[i]), end(group_val[i]));
            for (int ind = 0; ind < group_id[i].size(); ++ind)
                ans[group_id[i][ind]] = group_val[i][ind];
        }

        return ans;
    }
};

// Disjoint Set

struct disjoint_set
{
    vector<int> parent, count;
    disjoint_set(int n)
    {
        parent = vector<int>(n);
        count = vector<int>(n);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            count[i] = 1;
        }
    }

    int set_of(int x)
    {
        return x == parent[x] ? x : parent[x] = set_of(parent[x]);
    }

    void merge(int x, int y)
    {
        x = set_of(x);
        y = set_of(y);

        if (x == y)
            return;

        if (count[x] < count[y])
            swap(x, y);

        parent[y] = x;
        count[x] += count[y];
    }
};

class Solution
{

public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        int n = s.length();
        disjoint_set ds(n);
        for (auto pair : pairs)
            ds.merge(pair[0], pair[1]);

        vector<vector<int>> m(n);
        for (int i = 0; i < n; ++i)
            m[ds.set_of(i)].push_back(i);

        string ans = s;
        for (auto ids : m)
        {
            vector<char> group;
            for (auto id : ids)
                group.push_back(s[id]);
            sort(begin(group), end(group));
            for (int i = 0; i < ids.size(); ++i)
                ans[ids[i]] = group[i];
        }

        return ans;
    }
};