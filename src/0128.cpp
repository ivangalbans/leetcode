// https://leetcode.com/problems/longest-consecutive-sequence/

// Iterating in the sequence

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> s(begin(nums), end(nums));
        int ans = 0;

        for (auto x : nums)
        {
            if (!s.count(x - 1))
            {
                int y = x + 1;
                while (s.count(y))
                    ++y;
                ans = max(ans, y - x);
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
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();

        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i)
            m[nums[i]] = i + 1;

        disjoint_set ds(n + 1);
        for (auto num : nums)
        {
            int val = m[num - 1];
            if (val)
                ds.merge(m[num], val);
        }

        int ans = 0;
        for (auto num : nums)
            ans = max(ans, ds.count[ds.set_of(m[num])]);

        return ans;
    }
};