// https://leetcode.com/problems/range-frequency-queries/description/

// Segment Tree

#define left(x) ((x << 1) + 1)
#define right(x) ((x << 1) + 2)

struct Frequency
{
    unordered_map<int, int> freq;

    Frequency() {}

    Frequency(int value, int occ)
    {
        freq[value] = occ;
    }

    void merge(Frequency &f1, Frequency &f2)
    {
        for (auto &kv : f1.freq)
            freq[kv.first] = kv.second;
        for (auto &kv : f2.freq)
            freq[kv.first] += kv.second;
    }
};

template <class T>
class SegmentTree
{
private:
    vector<T> st;
    vector<int> arr;
    int n;

    void build(int node, int nodeL, int nodeR)
    {
        if (nodeL == nodeR)
        {
            st[node] = Frequency(arr[nodeL], 1);
            return;
        }

        int nodeM = (nodeL + nodeR) / 2;
        build(left(node), nodeL, nodeM);
        build(right(node), nodeM + 1, nodeR);
        st[node].merge(st[left(node)], st[right(node)]);
    }

    int query(int node, int nodeL, int nodeR, int left, int right, int val)
    {
        if (nodeL == left && nodeR == right)
            return st[node].freq[val];

        int nodeM = (nodeL + nodeR) / 2;
        if (right <= nodeM)
            return query(left(node), nodeL, nodeM, left, right, val);
        if (left > nodeM)
            return query(right(node), nodeM + 1, nodeR, left, right, val);
        return query(left(node), nodeL, nodeM, left, nodeM, val) +
               query(right(node), nodeM + 1, nodeR, nodeM + 1, right, val);
    }

public:
    SegmentTree() {}
    SegmentTree(vector<int> arr) : arr(arr)
    {
        n = arr.size();
        st = vector<Frequency>(4 * n);
        build(0, 0, n - 1);
    }

    int query(int left, int right, int value)
    {
        return query(0, 0, n - 1, left, right, value);
    }
};

class RangeFreqQuery
{
    SegmentTree<Frequency> st;

public:
    RangeFreqQuery(vector<int> &arr)
    {
        int n = arr.size();
        st = SegmentTree<Frequency>(arr);
    }

    int query(int left, int right, int value)
    {
        return st.query(left, right, value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */

// Binary Search

class RangeFreqQuery
{
private:
    vector<vector<int>> idx;

public:
    RangeFreqQuery(vector<int> &arr)
    {
        idx = vector<vector<int>>(100000 + 1, vector<int>());
        for (int i = 0; i < arr.size(); ++i)
            idx[arr[i]].push_back(i);
    }

    int query(int left, int right, int value)
    {
        int l = lower_bound(begin(idx[value]), end(idx[value]), left) - begin(idx[value]);
        int r = upper_bound(begin(idx[value]), end(idx[value]), right) - begin(idx[value]);
        return r - l;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */