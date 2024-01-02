// https://leetcode.com/problems/find-the-string-with-lcp/description/

// Greedy + DP

class Solution
{
public:
    string findTheString(vector<vector<int>> &lcp)
    {
        int n = lcp.size();
        char ch = 'a';

        // Build string (Greedy)
        string ans = "";
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j <= i && ans.length() == i; ++j)
                if (lcp[i][j])
                    ans += (j < i ? ans[j] : ch++);
            if (ans.size() && ans.back() > 'z')
                return "";
        }

        // Check if built string comply with LCP
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int cnt = (ans[i] == ans[j]);
                if (cnt && i + 1 < n && j + 1 < n)
                    cnt += lcp[i + 1][j + 1];
                if (lcp[i][j] != cnt)
                    return "";
            }
        }

        return ans;
    }
};

// Z-function

class Solution
{
public:
    vector<int> z_function(string s)
    {
        int n = (int)s.length();
        vector<int> z(n);

        for (int i = 1, l = 0, r = 0; i < n; ++i)
        {
            if (i <= r)
                z[i] = min(r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                ++z[i];
            if (i + z[i] - 1 > r)
                l = i, r = i + z[i] - 1;
        }
        return z;
    }

    string findTheString(vector<vector<int>> &lcp)
    {
        int n = lcp.size();
        char ch = 'a';

        // Build string (Greedy)
        string ans = "";
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j <= i && ans.length() == i; ++j)
                if (lcp[i][j])
                    ans += (j < i ? ans[j] : ch++);
            if (lcp[i][i] != n - i || (ans.size() && ans.back() > 'z'))
                return "";
        }

        // Check if built string comply with LCP
        for (int i = 0; i < n; ++i)
        {
            cout << ans.substr(i) << endl;
            auto z = z_function(ans.substr(i));
            for (int j = i + 1; j < n; ++j)
            {
                if (lcp[i][j] != lcp[j][i] || lcp[i][j] != z[j - i])
                    return "";
            }
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
    string findTheString(vector<vector<int>> &lcp)
    {
        int n = lcp.size();
        disjoint_set ds(n);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (lcp[i][j])
                    ds.merge(i, j);

        char ch = 'a';
        string ans = "";
        vector<char> seen(n, '$');
        for (int i = 0; i < n; ++i)
        {
            int x = ds.set_of(i);
            if (seen[x] == '$')
                seen[x] = ch++;
            ans += seen[x];
            if (ans.back() > 'z')
                return "";
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int cnt = (ans[i] == ans[j]);
                if (cnt && i + 1 < n && j + 1 < n)
                    cnt += lcp[i + 1][j + 1];
                if (lcp[i][j] != cnt)
                    return "";
            }
        }

        return ans;
    }
};