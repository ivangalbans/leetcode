// https://leetcode.com/problems/sort-an-array/description/

// Mergesort

class Solution
{
public:
    void merge(vector<int> &nums, int lo, int mid, int hi)
    {
        vector<int> temp(hi - lo + 1);
        int index = 0;
        int l = lo, r = mid + 1;
        while (l <= mid && r <= hi)
            temp[index++] = (nums[l] <= nums[r]) ? nums[l++] : nums[r++];
        while (l <= mid)
            temp[index++] = nums[l++];
        while (r <= hi)
            temp[index++] = nums[r++];
        copy(begin(temp), end(temp), begin(nums) + lo);

        return;
    }

    void merge_sort(vector<int> &nums, int lo, int hi)
    {
        if (lo >= hi)
            return;

        int mid = (lo + hi) / 2;
        merge_sort(nums, lo, mid);
        merge_sort(nums, mid + 1, hi);
        merge(nums, lo, mid, hi);

        return;
    }

    void merge_sort(vector<int> &nums)
    {
        merge_sort(nums, 0, nums.size() - 1);
        return;
    }

    vector<int> sortArray(vector<int> &nums)
    {
        merge_sort(nums);
        return nums;
    }
};

// Quicksort

class Solution
{
public:
    int partition(vector<int> &a, int l, int r)
    {
        int p = l + (rand() % (r - l + 1));
        swap(a[p], a[r]);

        int i = l;
        for (int j = l; j < r; ++j)
        {
            if (a[j] < a[r])
            {
                swap(a[i], a[j]);
                i++;
            }
        }
        swap(a[i], a[r]);
        return i;
    }

    bool sorted(vector<int> &nums, int l, int r)
    {
        for (int i = l; i < r; ++i)
            if (nums[i] > nums[i + 1])
                return false;
        return true;
    }

    void quick_sort(vector<int> &a, int l, int r)
    {
        if (l >= r || sorted(a, l, r))
            return;

        int p = partition(a, l, r);
        quick_sort(a, l, p - 1);
        quick_sort(a, p + 1, r);
    }

    void quick_sort(vector<int> &a)
    {
        quick_sort(a, 0, a.size() - 1);
    }

    vector<int> sortArray(vector<int> &nums)
    {
        quick_sort(nums);
        return nums;
    }
};

// Heapsort

#define left(x) ((x << 1) + 1)
#define right(x) ((x << 1) + 2)

class Solution
{
public:
    void max_heapify(vector<int> &a, int i, int heap_size)
    {
        int l, r, largest = i;
        do
        {
            i = largest;
            l = left(i);
            r = right(i);
            if (l < heap_size && a[l] > a[largest])
                largest = l;
            if (r < heap_size && a[r] > a[largest])
                largest = r;

            swap(a[largest], a[i]);
        } while (largest != i);
    }

    void build_max_heap(vector<int> &a)
    {
        int heap_size = a.size();
        for (int i = heap_size / 2; i >= 0; --i)
            max_heapify(a, i, heap_size);
    }

    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();
        int heap_size = n;

        build_max_heap(nums);
        for (int i = n - 1; i >= 0; --i)
        {
            swap(nums[0], nums[i]);
            heap_size--;
            max_heapify(nums, 0, heap_size);
        }

        return nums;
    }
};

// Bucketsort

class Solution
{
public:
    const int MAXN = 100000;
    vector<int> bucket_sort(vector<int> &a)
    {
        int n = a.size();
        vector<vector<int>> b(MAXN / n + 1);

        for (auto x : a)
            b[x / n].push_back(x);

        for (auto &bucket : b)
            sort(begin(bucket), end(bucket));

        vector<int> ans;
        for (auto &bucket : b)
            for (auto x : bucket)
                ans.push_back(x);

        return ans;
    }

    vector<int> sortArray(vector<int> &nums)
    {
        int k = 5 * 10000;

        for (auto &x : nums)
            x += k;
        auto sorted = bucket_sort(nums);
        for (auto &x : sorted)
            x -= k;

        return sorted;
    }
};

// Radix sort

class Solution
{
public:
    int digit(int x, int d)
    {
        int base = pow(10, d);
        return (x % (base * 10)) / base;
    }
    void counting_sort(vector<int> &a, int d)
    {
        int n = a.size();
        vector<int> b(n), c(10);

        for (auto x : a)
            c[digit(x, d)]++;

        for (int i = 1; i <= 9; ++i)
            c[i] += c[i - 1];

        for (int i = n - 1; i >= 0; --i)
            b[--c[digit(a[i], d)]] = a[i];

        a = b;
    }

    void radix_sort(vector<int> &a, int d)
    {
        for (int i = 0; i < d; i++)
            counting_sort(a, i);
    }

    vector<int> sortArray(vector<int> &nums)
    {
        int k = 5 * 10000;

        for (auto &x : nums)
            x += k;
        radix_sort(nums, 6);
        for (auto &x : nums)
            x -= k;

        return nums;
    }
};

// Counting sort

class Solution
{
public:
    vector<int> counting_sort(vector<int> &a, int k)
    {
        int n = a.size();
        vector<int> b(n), c(k + 1);

        for (auto x : a)
            c[x]++;

        for (int i = 1; i <= k; ++i)
            c[i] += c[i - 1];

        for (int i = n - 1; i >= 0; --i)
            b[--c[a[i]]] = a[i];

        return b;
    }

    vector<int> sortArray(vector<int> &nums)
    {
        int k = 5 * 10000;

        for (auto &x : nums)
            x += k;
        auto sorted_nums = counting_sort(nums, 2 * k);
        for (auto &x : sorted_nums)
            x -= k;

        return sorted_nums;
    }
};
