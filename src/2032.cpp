class Solution
{
public:
  vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
  {
    vector<int> mk1(101), mk2(101), mk3(101);
    vector<int> ans;
    for (auto x : nums1)
      mk1[x] = min(1, mk2[x] + 1);
    for (auto x : nums2)
      mk2[x] = min(1, mk2[x] + 1);
    for (auto x : nums3)
      mk3[x] = min(1, mk3[x] + 1);
    for (int i = 1; i <= 100; ++i)
      if (mk1[i] + mk2[i] + mk3[i] >= 2)
        ans.push_back(i);
    return ans;
  }
};