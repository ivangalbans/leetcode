// https://leetcode.com/problems/append-k-integers-with-minimal-sum/

class Solution {
public:
  long long minimalKSum(vector<int> &nums, int k) {
    sort(begin(nums), end(nums));
    auto last = unique(begin(nums), end(nums));
    nums.erase(last, end(nums));

    long long sum = (long long)k * ((long long)k + 1) / 2;

    int cur = k + 1;
    for (auto &x : nums) {
      if (x < cur) {
        sum -= x;
        sum += cur++;
      }
    }

    return sum;
  }
};
