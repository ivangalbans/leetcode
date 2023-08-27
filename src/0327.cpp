// https://leetcode.com/problems/count-of-range-sum/description/

// Fenwick Tree

template <class T>
struct bit
{
    vector<T> ft;
    bit(int n) : ft(n + 1, 0) {}

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

    // inclusive
    T query(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};

class Solution
{
public:
    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        int n = nums.size();

        vector<long long> s(n + 1);
        for (int i = 0; i < n; ++i)
            s[i + 1] = s[i] + (long long)nums[i];

        vector<long long> nums2;
        for (int i = 0; i < s.size(); ++i)
        {
            nums2.push_back(s[i]);
            nums2.push_back((long long)lower + s[i]);
            nums2.push_back((long long)upper + s[i]);
        }

        set<long long> compress(begin(nums2), end(nums2));
        int len = 0;
        unordered_map<long long, int> rank;
        for (auto x : compress)
            rank[x] = ++len;

        bit<int> ft(len);
        int ans = 0;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            ans += ft.query(rank[lower + s[i]], rank[upper + s[i]]);
            ft.update(rank[s[i]], 1);
        }

        return ans;
    }
};

// MergeSort

class Solution
{
public:
    int mergeSort(vector<long long> &sum, int l, int r, int lower, int upper)
    {
        if (l >= r)
            return 0;

        int m = (l + r) / 2;
        int c = mergeSort(sum, l, m, lower, upper) + mergeSort(sum, m + 1, r, lower, upper);
        vector<long long> temp(r - l + 1);
        int index = 0, i = l, j = m + 1;
        int k1 = m + 1, k2 = m + 1;

        while (i <= m)
        {
            while (k1 <= r && sum[k1] - sum[i] < lower)
                ++k1;
            while (k2 <= r && sum[k2] - sum[i] <= upper)
                ++k2;
            c += k2 - k1;
            while (j <= r && sum[j] <= sum[i])
                temp[index++] = sum[j++];
            temp[index++] = sum[i++];
        }

        while (j <= r)
            temp[index++] = sum[j++];
        copy(begin(temp), end(temp), begin(sum) + l);

        return c;
    }

    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        int n = nums.size();
        vector<long long> sum(n + 1);
        for (int i = 1; i <= n; ++i)
            sum[i] = sum[i - 1] + nums[i - 1];

        return mergeSort(sum, 0, n, lower, upper);
    }
};