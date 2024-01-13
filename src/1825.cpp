// https://leetcode.com/problems/finding-mk-average/description/

// Fenwick Tree + Binary Search

struct fenwick_tree
{
    vector<long long> ft;

    fenwick_tree() {}

    fenwick_tree(int n)
    {
        ft = vector<long long>(n);
    }

    int lowbit(int x)
    {
        return x & -x;
    }

    void update(int pos, int val)
    {
        for (; pos < ft.size(); pos += lowbit(pos))
            ft[pos] += val;
    }

    long long query(int pos)
    {
        long long sum = 0;
        for (; pos > 0; pos -= lowbit(pos))
            sum += ft[pos];
        return sum;
    }
};

class MKAverage
{
private:
    deque<int> stream;
    int m, k;
    fenwick_tree vals;
    fenwick_tree index;

    int binary_search(int x)
    {
        int lo = 0, hi = 100000;
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if (index.query(mid) < x)
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo;
    }

public:
    MKAverage(int m, int k) : m(m), k(k)
    {
        vals = fenwick_tree(100001);
        index = fenwick_tree(100001);
    }

    void addElement(int num)
    {
        stream.push_back(num);
        vals.update(num, num);
        index.update(num, 1);
        if (stream.size() == m + 1)
        {
            vals.update(stream[0], -stream[0]);
            index.update(stream[0], -1);
            stream.pop_front();
        }
    }

    int calculateMKAverage()
    {
        if (stream.size() < m)
            return -1;

        int l = binary_search(k);
        int r = binary_search(m - k);
        long long sum = vals.query(r) - vals.query(l);
        sum += (index.query(l) - k) * l;
        sum -= (index.query(r) - (m - k)) * r;

        return sum / (m - 2 * k);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */

// 3 Multisets
