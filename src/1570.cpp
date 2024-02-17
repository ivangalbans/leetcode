// https://leetcode.com/problems/dot-product-of-two-sparse-vectors/description/

class SparseVector
{
private:
    vector<pair<int, int>> nums;

public:
    SparseVector(vector<int> &v)
    {
        for (int i = 0; i < v.size(); ++i)
            if (v[i])
                nums.push_back({i, v[i]});
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector &vec)
    {
        int n = nums.size(), m = vec.nums.size();
        int result = 0;

        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (nums[i].first < vec.nums[j].first)
                ++i;
            else if (nums[i].first > vec.nums[j].first)
                ++j;
            else
            {
                result += nums[i].second * vec.nums[j].second;
                ++i;
                ++j;
            }
        }

        return result;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);