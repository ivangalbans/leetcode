// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/

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

    int merge(int x, int y)
    {
        x = set_of(x);
        y = set_of(y);

        if (x == y)
            return x;

        if (count[x] < count[y])
            swap(x, y);

        parent[y] = x;
        count[x] += count[y];

        return x;
    }
};

class Solution
{
public:
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {

        vector<char> small_char(26);
        iota(begin(small_char), end(small_char), 'a');

        disjoint_set ds(26);
        for (int i = 0; i < s1.length(); ++i)
        {
            int set_of = ds.merge(s1[i] - 'a', s2[i] - 'a');
            small_char[set_of] = min({small_char[set_of], s1[i], s2[i]});
        }

        string ans = baseStr;
        for (int i = 0; i < ans.size(); ++i)
            ans[i] = small_char[ds.set_of(ans[i] - 'a')];

        return ans;
    }
};