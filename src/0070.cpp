// https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
  int climbStairs(int n) {

    if (n == 1)
      return 1;

    int a = 1, b = 1;
    for (int i = 2; i <= n; ++i) {
      int temp = b;
      b = a + b;
      a = temp;
    }

    return b;
  }
};
