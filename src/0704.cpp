// https://leetcode.com/problems/binary-search/

class Solution
{
public:
  int search(vector<int> &nums, int target)
  {
    int lo = 0, hi = nums.size() - 1;
    while (lo <= hi)
    {
      int mid = (lo + hi) / 2;
      if (nums[mid] == target)
        return mid;
      else if (nums[mid] < target)
        lo = mid + 1;
      else
        hi = mid - 1;
    }
    return -1;
  }
};
