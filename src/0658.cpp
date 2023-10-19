// https://leetcode.com/problems/find-k-closest-elements/

// Priority Queue O(n * log(n))
// Don't need the sorted array

typedef pair<int, int> pii;

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        priority_queue<pii, vector<pii>, greater<pii>> pq = priority_queue<pii, vector<pii>, greater<pii>>();
        for (auto &a : arr)
            pq.push(pii(abs(x - a), a));

        vector<int> ans(k);
        for (int i = 0; i < k; ++i)
        {
            ans[i] = pq.top().second;
            pq.pop();
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};

// Considering the list is sorted
// Binary Search + Two Pointers O(log(n) + k)

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int n = arr.size();
        deque<int> ans;
        int l = lower_bound(begin(arr), end(arr), x) - begin(arr);
        if (l == n || (l > 0 && x - arr[l - 1] <= arr[l] - x))
            --l;
        int r = l;
        ans.push_back(arr[l]);
        --k;
        --l;
        ++r;

        while (k && l >= 0 && r < n)
        {
            if (abs(arr[l] - x) <= abs(arr[r] - x))
                ans.push_front(arr[l--]);
            else
                ans.push_back(arr[r++]);
            --k;
        }

        while (k && l >= 0)
        {
            ans.push_front(arr[l--]);
            k--;
        }

        while (k && r < n)
        {
            ans.push_back(arr[r++]);
            k--;
        }

        return vector<int>(begin(ans), end(ans));
    }
};