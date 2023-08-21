// https://leetcode.com/problems/reverse-pairs/description/

// Compress using maps

template <class T>
struct BIT
{
public:
    vector<T> ft;
    BIT(int n) : ft(n + 1, 0) {}

    int lowbit(int x)
    {
        return x & -x;
    }

    void update(int pos, T val)
    {
        for (; pos < ft.size(); pos += lowbit(pos))
            ft[pos] += val;
    }

    T query(int pos)
    {
        T sum = 0;
        for (; pos > 0; pos -= lowbit(pos))
            sum += ft[pos];
        return sum;
    }
};

class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();

        vector<long long> nums2(2 * n);
        for (int i = 0; i < 2 * n; ++i)
            nums2[i] = i < n ? nums[i] : 2ll * nums[i - n];

        set<long long> s(begin(nums2), end(nums2));
        unordered_map<long long, int> rank;
        int index = 0;
        for (auto x : s)
            rank[x] = ++index;

        BIT<int> bit(s.size());
        int rpairs = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            rpairs += bit.query(rank[nums[i]] - 1);
            bit.update(rank[2ll * nums[i]], 1);
        }

        return rpairs;
    }
};

// Compress using sort

template <class T>
struct BIT
{
public:
    vector<T> ft;
    BIT(int n) : ft(n + 1, 0) {}

    int lowbit(int x)
    {
        return x & -x;
    }

    void update(int pos, T val)
    {
        for (; pos < ft.size(); pos += lowbit(pos))
            ft[pos] += val;
    }

    T query(int pos)
    {
        T sum = 0;
        for (; pos > 0; pos -= lowbit(pos))
            sum += ft[pos];
        return sum;
    }
};

struct Node
{
    long long val;
    int index, rank;
};

bool cmp_val(Node a, Node b)
{
    return a.val < b.val;
}

bool cmp_index(Node a, Node b)
{
    return a.index < b.index;
}

class Solution
{
public:
    int compress(vector<Node> &nums)
    {
        sort(begin(nums), end(nums), cmp_val);

        nums[0].rank = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i - 1].val == nums[i].val)
                nums[i].rank = nums[i - 1].rank;
            else
                nums[i].rank = nums[i - 1].rank + 1;
        }

        int len = nums[nums.size() - 1].rank;
        sort(begin(nums), end(nums), cmp_index);
        return len;
    }

    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();

        vector<Node> nums2(2 * n);
        for (int i = 0; i < 2 * n; ++i)
        {
            if (i < n)
            {
                nums2[i].val = nums[i];
                nums2[i].index = i;
            }
            else
            {
                nums2[i].val = 2ll * nums[i - n];
                nums2[i].index = i;
            }
        }

        int len = compress(nums2);
        BIT<int> bit(len);
        int rpairs = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            rpairs += bit.query(nums2[i].rank - 1);
            bit.update(nums2[i + n].rank, 1);
        }

        return rpairs;
    }
};