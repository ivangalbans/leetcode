// https://leetcode.com/problems/sort-the-jumbled-numbers/

class Solution {
public:
  int change(vector<int> &mapping, int x) {
    string s = to_string(x);
    int num = 0;
    for (auto d : s)
      num = num * 10 + mapping[d - '0'];
    return num;
  }

  vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums) {

    int n = nums.size();
    vector<pair<int, pair<int, int>>> v(n);
    for (int i = 0; i < n; ++i)
      v[i] = make_pair(change(mapping, nums[i]), make_pair(i, nums[i]));

    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i)
      nums[i] = v[i].second.second;

    return nums;
  }
};
