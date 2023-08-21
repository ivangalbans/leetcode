// https://leetcode.com/problems/range-sum-query-mutable/description/

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