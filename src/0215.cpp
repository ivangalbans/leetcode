// https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> pq;
        for (auto num : nums)
            pq.push(num);
        while (--k)
            pq.pop();
        return pq.top();
    }
};

// Heap

#define left(x) ((x << 1) + 1)
#define right(x) ((x << 1) + 2)
#define parent(x) ((x - 1) / 2)

class heap_max
{
private:
    vector<int> a;
    int oo = (1 << 30);

    void max_heapify(int i)
    {
        int l, r, largest = i;
        do
        {
            i = largest;
            l = left(i);
            r = right(i);

            if (l < size && a[l] > a[largest])
                largest = l;
            if (r < size && a[r] > a[largest])
                largest = r;

            swap(a[largest], a[i]);
        } while (largest != i);
    }

    void max_heapify_up(int i)
    {
        while (i >= 0 && a[i] > a[parent(i)])
        {
            swap(a[i], a[parent(i)]);
            i = parent(i);
        }
    }

    void increase_key(int i, int key)
    {
        if (key <= a[i])
            return;

        a[i] = key;
        max_heapify_up(i);
    }

public:
    int size;

    heap_max() : size(0) {}

    heap_max(vector<int> &input)
    {
        size = input.size();
        a = vector<int>(begin(input), end(input));
        build();
    }

    void build()
    {
        for (int i = size / 2; i >= 0; --i)
            max_heapify(i);
    }

    void insert(int val)
    {
        if (size == a.size())
            a.push_back(-oo);
        else
            a[size] = -oo;

        size++;
        increase_key(size - 1, val);
    }

    int max()
    {
        return a[0];
    }

    int extract_max()
    {
        int max = a[0];
        size--;
        swap(a[0], a[size]);
        max_heapify(0);
        return max;
    }
};

class priority_queue_max
{
private:
    heap_max heap;

public:
    priority_queue_max() {}

    priority_queue_max(vector<int> &input)
    {
        heap = heap_max(input);
    }

    void push(int val)
    {
        heap.insert(val);
    }

    void pop()
    {
        heap.extract_max();
    }

    int top()
    {
        return heap.max();
    }
};

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue_max pq;
        for (auto num : nums)
            pq.push(num);

        while (--k)
            pq.pop();
        return pq.top();
    }

    // int findKthLargest(vector<int>& nums, int k) {
    //     priority_queue_max pq(nums);
    //     while(--k)
    //         pq.pop();
    //     return pq.top();
    // }
};