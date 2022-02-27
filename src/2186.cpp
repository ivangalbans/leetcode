// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/

class Solution {
public:
  int minSteps(string s, string t) {
    vector<int> alpha1(26);
    vector<int> alpha2(26);

    for (auto ch : s)
      alpha1[ch - 'a']++;

    for (auto ch : t)
      alpha2[ch - 'a']++;

    int ans = 0;

    for (int i = 0; i < 26; ++i) {
      ans += abs(alpha1[i] - alpha2[i]);
    }

    return ans;
  }
};

int main() {
  Solution sol;

  cout << sol.minSteps("leetcode", "coats") << endl;
  cout << sol.minSteps("night", "thing");
  return 0;
}
