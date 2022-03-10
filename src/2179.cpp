// https://leetcode.com/problems/count-good-triplets-in-an-array/

template <class T> struct abi {
  vector<T> ft;
  abi(int n) : ft(n + 1, 0) {}

  int lowbit(int x) { return x & -x; }

  void update(int pos, T val) {
    for (; pos < ft.size(); pos += lowbit(pos))
      ft[pos] += val;
  }

  T query(int pos) {
    T sum = 0;
    for (; pos > 0; pos -= lowbit(pos))
      sum += ft[pos];
    return sum;
  }
};

class Solution {
public:
  void pairs(vector<int> &nums1, vector<int> &nums2, vector<long long> &ans) {
    int n = nums1.size();
    vector<int> pos(n);
    for (int i = 0; i < n; ++i)
      pos[nums2[i]] = i + 1;

    abi<int> ft(n);
    for (int i = 0; i < n; ++i) {
      ans[i] = ft.query(pos[nums1[i]]);
      ft.update(pos[nums1[i]], 1);
    }
  }

  long long goodTriplets(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();

    vector<long long> dp1(n), dp2(n);
    pairs(nums1, nums2, dp1);
    reverse(begin(nums1), end(nums1));
    reverse(begin(nums2), end(nums2));
    pairs(nums1, nums2, dp2);
    reverse(begin(dp2), end(dp2));

    long long ans = 0;
    for (int i = 0; i < n; ++i)
      ans += dp1[i] * dp2[i];

    return ans;
  }
};
