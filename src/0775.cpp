// https://leetcode.com/problems/global-and-local-inversions/description/

// Inversions using MergeSort

class Solution
{
public:
    long long merge(vector<int> &nums, int lo, int mid, int hi)
    {
        vector<int> temp(hi - lo + 1);
        int index = 0, inv = 0;
        int l = lo, r = mid + 1;
        while (l <= mid && r <= hi)
        {
            if (nums[l] <= nums[r])
            {
                temp[index++] = nums[l++];
            }
            else
            {
                temp[index++] = nums[r++];
                inv += (mid + 1 - l);
            }
        }
        while (l <= mid)
            temp[index++] = nums[l++];
        while (r <= hi)
            temp[index++] = nums[r++];
        copy(begin(temp), end(temp), begin(nums) + lo);

        return inv;
    }

    long long merge_sort(vector<int> &nums, int lo, int hi)
    {
        if (lo >= hi)
            return 0;

        int mid = (lo + hi) / 2;
        long long left = merge_sort(nums, lo, mid);
        long long right = merge_sort(nums, mid + 1, hi);
        long long comb = merge(nums, lo, mid, hi);
        return left + right + comb;
    }

    long long global_inversions(vector<int> nums)
    {
        return merge_sort(nums, 0, nums.size() - 1);
    }

    long long local_inversions(vector<int> &nums)
    {
        int local = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
            if (nums[i] > nums[i + 1])
                ++local;
        return local;
    }

    bool isIdealPermutation(vector<int> &nums)
    {
        return global_inversions(nums) == local_inversions(nums);
    }
};

// Inversions using Fenwick Tree

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
};

class Solution
{
public:
    long long global_inversions(vector<int> &nums)
    {
        int n = nums.size();
        bit<int> ft(n);
        long long inv = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            inv += ft.query(nums[i] + 1);
            ft.update(nums[i] + 1, 1);
        }
        return inv;
    }

    long long local_inversions(vector<int> &nums)
    {
        int local = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
            if (nums[i] > nums[i + 1])
                ++local;
        return local;
    }

    bool isIdealPermutation(vector<int> &nums)
    {
        return global_inversions(nums) == local_inversions(nums);
    }
};