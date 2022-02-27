// https://leetcode.com/problems/minimum-time-to-complete-trips/

class Solution {
public:
  long long f(vector<int> &time, long long t) {
    long long ans = 0;
    for (auto &x : time)
      ans += t / x;
    return ans;
  }

  long long minimumTime(vector<int> &time, int totalTrips) {
    long long lo = 1, hi = 100000000000000L + 5;
    while (lo <= hi) {
      long long mid = (lo + hi) / 2;
      if (f(time, mid) < totalTrips)
        lo = mid + 1;
      else
        hi = mid - 1;
    }

    return lo;
  }
};
