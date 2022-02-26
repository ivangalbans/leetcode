#include <bits/stdc++.h>

using namespace std;

/////////////////////////////////////////////////
typedef long long Int;
typedef pair<int, int> pii;
typedef vector<int> vi;
/////////////////////////////////////////////////
#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define FOR(i, n) for (int i = 1; i <= (int)n; ++i)
#define ITR(c) __typeof((c).begin())
#define foreach(i, c) for (ITR(c) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define DB(x) cout << #x << " = " << x << endl

#define endl '\n'
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define LEFT(n) ((n << 1) + 1)
#define RIGHT(n) ((n << 1) + 2)
#define BIT(n) (1 << n)
#define ONES(n) __builtin_popcount(n)
#define rightZero(n) __builtin_ctz(n); // trailing zeros
#define leftZero(n) __builtin_clz(n);  // leading zeros

/////////////////////////////////////////////////
const double EPS = 1e-15;
const int oo = (1 << 30);
const double PI = M_PI;
const int MOD = 1000000000 + 7;
/////////////////////////////////////////////////

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); ++i) {
      if (map.count(target - nums[i]))
        return {map[target - nums[i]], i};
      map[nums[i]] = i;
    }

    return {-1, -1};
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  // vi v = {2, 7, 11, 15};
  // int k = 9;

  // vi v = {3, 3};
  // int k = 6;

  vi v = {3, 2, 4};
  int k = 6;

  Solution sol;
  vi ans = sol.twoSum(v, k);

  for (auto x : ans)
    cout << x << " ";

  return 0;
}
