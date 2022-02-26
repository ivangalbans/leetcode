// https://leetcode.com/problems/count-integers-with-even-digit-sum/

class Solution {
public:
  int count(int n) {
    int sum = 0;
    while (n) {
      sum += n % 10;
      n /= 10;
    }

    return sum;
  }

  int countEven(int num) {
    int ans = 0;
    for (int i = 1; i <= num; ++i) {
      if (count(i) % 2 == 0)
        ans++;
    }
    return ans;
  }
};
