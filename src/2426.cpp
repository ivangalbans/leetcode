// https://leetcode.com/problems/number-of-pairs-satisfying-inequality/description/

template <class T>
class FenwickTree
{
private:
    vector<T> ft;

    int lowbit(int x)
    {
        return x & -x;
    }

public:
    FenwickTree(int n) : ft(n + 1) {}

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
private:
    const long long MAX = 10000;
    const long long shift = 3 * MAX + 1;

public:
    long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int diff)
    {
        int n = nums1.size();
        FenwickTree<long long> ft(9 * shift);
        long long ans = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            ans += ft.query(nums2[i] - nums1[i] + diff + shift);
            ft.update(nums2[i] - nums1[i] + shift, 1);
        }
        return ans;
    }
};