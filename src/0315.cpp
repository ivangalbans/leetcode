// https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/

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
    const int N = 10000;
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        for (auto &x : nums)
            x += N + 1;

        vector<int> ans(n);
        bit<int> ft(2 * N);

        for (int i = n - 1; i >= 0; --i)
        {
            ans[i] = ft.query(nums[i] - 1);
            ft.update(nums[i], 1);
        }

        return ans;
    }
};