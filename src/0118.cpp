// https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pascal(numRows);

    pascal[0].push_back(1);

    for (int r = 1; r < numRows; ++r) {
      pascal[r].push_back(1);
      for (int c = 1; c < pascal[r - 1].size(); ++c)
        pascal[r].push_back(pascal[r - 1][c] + pascal[r - 1][c - 1]);
      pascal[r].push_back(1);
    }

    return pascal;
  }
};
