// https://leetcode.com/problems/range-sum-query-mutable/description/

// Fenwick Tree

class NumArray
{
public:
    vector<int> bit;
    vector<int> nums2;

    NumArray(vector<int> &nums)
    {
        int n = nums.size();
        nums2 = nums;
        bit = vector<int>(n + 1);

        for (int i = 0; i < n; ++i)
            init(i, nums[i]);
    }

    int lowbit(int x)
    {
        return x & -x;
    }

    void init(int index, int val)
    {
        int pos = index + 1;
        for (; pos < bit.size(); pos += lowbit(pos))
            bit[pos] += val;
    }

    void update(int index, int val)
    {
        int diff = val - nums2[index];
        nums2[index] = val;
        int pos = index + 1;

        for (; pos < bit.size(); pos += lowbit(pos))
            bit[pos] += diff;
    }

    int query(int index)
    {
        int sum = 0;
        int pos = index + 1;
        for (; pos > 0; pos -= lowbit(pos))
            sum += bit[pos];
        return sum;
    }

    int sumRange(int left, int right)
    {
        return left == 0 ? query(right) : query(right) - query(left - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

// Segment Tree

#define left(x) ((x << 1) + 1)
#define right(x) ((x << 1) + 2)

struct segment_tree
{
    vector<int> st;
    vector<int> items;
    int n;

    segment_tree() {}

    segment_tree(vector<int> items) : items(items)
    {
        n = items.size();
        st = vector<int>(4 * n);
        build(0, 0, n - 1);
    }

    void build(int node, int nodeL, int nodeR)
    {
        if (nodeL == nodeR)
        {
            st[node] = items[nodeL];
            return;
        }

        int nodeM = (nodeL + nodeR) / 2;
        build(left(node), nodeL, nodeM);
        build(right(node), nodeM + 1, nodeR);
        st[node] = st[left(node)] + st[right(node)];
    }

    void update(int node, int nodeL, int nodeR, int pos, int val)
    {
        if (nodeL == nodeR)
        {
            st[node] = val;
            return;
        }

        int nodeM = (nodeL + nodeR) / 2;
        if (pos <= nodeM)
            update(left(node), nodeL, nodeM, pos, val);
        else
            update(right(node), nodeM + 1, nodeR, pos, val);
        st[node] = st[left(node)] + st[right(node)];
    }

    int query(int node, int nodeL, int nodeR, int left, int right)
    {
        if (nodeL == left && nodeR == right)
            return st[node];

        int nodeM = (nodeL + nodeR) / 2;
        if (right <= nodeM)
            return query(left(node), nodeL, nodeM, left, right);
        if (left > nodeM)
            return query(right(node), nodeM + 1, nodeR, left, right);
        return query(left(node), nodeL, nodeM, left, nodeM) +
               query(right(node), nodeM + 1, nodeR, nodeM + 1, right);
    }

    int query(int left, int right)
    {
        return query(0, 0, n - 1, left, right);
    }

    void update(int pos, int val)
    {
        items[pos] = val;
        update(0, 0, n - 1, pos, val);
    }
};

class NumArray
{
public:
    segment_tree st;
    NumArray(vector<int> &nums)
    {
        st = segment_tree(nums);
    }

    void update(int index, int val)
    {
        st.update(index, val);
    }

    int sumRange(int left, int right)
    {
        return st.query(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */