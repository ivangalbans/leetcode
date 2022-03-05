// https://leetcode.com/problems/get-maximum-in-generated-array/

class Solution {
public:
  int getMaximumGenerated(int n) {
    if (n == 0 || n == 1)
      return n;

    vector<int> v(n + 1);
    v[0] = 0;
    v[1] = 1;
    int ans = 1;

    for (int i = 2; i <= n; i++) {
      v[i] = i % 2 == 0 ? v[i >> 1] : v[i >> 1] + v[(i >> 1) + 1];
      ans = max(ans, v[i]);
    }

    return ans;
  }
};
