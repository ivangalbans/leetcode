// https://leetcode.com/problems/find-if-array-can-be-sorted/description/

class Solution
{
public:
    bool canSortArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<pair<int, int>> seg;
        int l = 0, r = 0;
        while (l < n)
        {
            while (r < n && __builtin_popcount(nums[l]) == __builtin_popcount(nums[r]))
                ++r;
            seg.push_back({l, r - 1});
            l = r;
        }

        for (int i = 0; i + 1 < seg.size(); ++i)
        {
            auto [i1, j1] = seg[i];
            auto [i2, j2] = seg[i + 1];
            int last = *max_element(begin(nums) + i1, begin(nums) + j1 + 1);
            int beg = *min_element(begin(nums) + i2, begin(nums) + j2 + 1);
            if (last > beg)
                return false;
        }

        return true;
    }
};

// Disjoint set

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
    bool canSortArray(vector<int> &nums)
    {
        disjoint_set ds(257);
        int n = nums.size();
        vector<int> v(begin(nums), end(nums));
        sort(begin(v), end(v));

        for (int i = 0; i < n - 1; ++i)
        {
            if (__builtin_popcount(nums[i]) == __builtin_popcount(nums[i + 1]))
                ds.merge(nums[i], nums[i + 1]);
        }

        for (int i = 0; i < n; ++i)
        {
            if (ds.set_of(v[i]) != ds.set_of(nums[i]))
            {
                return false;
            }
        }

        return true;
    }
};