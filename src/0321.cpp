// https://leetcode.com/problems/create-maximum-number/description/

class Solution
{
public:
    vector<int> maxNumber(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> q;

        for (int i = 0; i < n; ++i)
        {
            while (!q.empty() && q.back() < nums[i] && q.size() - 1 + n - i >= k)
                q.pop_back();
            q.push_back(nums[i]);
        }

        q.resize(k);
        return q;
    }

    bool greater(vector<int> &nums1, int l, vector<int> &nums2, int r)
    {
        int n = nums1.size(), m = nums2.size();
        while (l < n && r < m && nums1[l] == nums2[r])
            ++l, ++r;
        return r == m || (l < n && nums1[l] > nums2[r]);
    }

    vector<int> merge(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();
        vector<int> ans(n + m);
        int l = 0, r = 0;
        while (l < n && r < m)
        {
            if (greater(nums1, l, nums2, r))
                ans[l + r] = nums1[l], ++l;
            else
                ans[l + r] = nums2[r], ++r;
        }

        while (l < n)
            ans[l + r] = nums1[l], l++;
        while (r < m)
            ans[l + r] = nums2[r], r++;

        return ans;
    }

    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int n = nums1.size(), m = nums2.size();

        vector<int> v1, v2, vmerge, ans;
        for (int i = 0; i <= min(k, n); ++i)
        {
            int l = min(i, k);
            int r = k - i;
            if (r <= m)
            {
                v1 = maxNumber(nums1, i);
                v2 = maxNumber(nums2, k - i);
                vmerge = merge(v1, v2);
                if (vmerge > ans)
                    ans = vmerge;
            }
        }

        return ans;
    }
};