// https://leetcode.com/problems/kth-missing-positive-number/description/

class Solution
{
public:
    int missing(vector<int> &arr, int pos)
    {
        return arr[pos] - (pos + 1);
    }

    int findKthPositive(vector<int> &arr, int k)
    {
        int lo = 0, hi = arr.size() - 1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;

            if (missing(arr, mid) < k)
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        return lo + k;
    }
};