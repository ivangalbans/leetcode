// https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/description/

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
    int minimumHammingDistance(vector<int> &source, vector<int> &target, vector<vector<int>> &allowedSwaps)
    {
        int n = source.size();

        disjoint_set ds(n);
        for (auto edge : allowedSwaps)
            ds.merge(edge[0], edge[1]);

        vector<unordered_multiset<int>> groups(n);
        for (int i = 0; i < n; ++i)
            groups[ds.set_of(i)].insert(source[i]);

        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            auto &group = groups[ds.set_of(i)];
            auto it = group.find(target[i]);
            if (it == end(group))
                ans++;
            else
                group.erase(it);
        }

        return ans;
    }
};