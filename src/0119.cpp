// https://leetcode.com/problems/pascals-triangle-ii/

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    ++rowIndex;
    vector<int> prev;
    vector<int> curr = {1};

    for (int r = 1; r < rowIndex; ++r) {
      prev = curr;
      curr.clear();
      curr.push_back(1);
      for (int c = 1; c < prev.size(); ++c)
        curr.push_back(prev[c] + prev[c - 1]);
      curr.push_back(1);
    }

    return curr;
  }
};
