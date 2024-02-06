// https://leetcode.com/problems/friends-of-appropriate-ages/

// O(n * log(n))

class Solution
{
public:
    int numFriendRequests(vector<int> &ages)
    {
        int n = ages.size();
        sort(begin(ages), end(ages));

        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int l = upper_bound(begin(ages), end(ages), 0.5 * ages[i] + 7) - begin(ages);
            int r = i;
            while (r + 1 < n && ages[r] == ages[r + 1])
                ++r;
            if (l <= r)
                ans += (r - l);
        }

        return ans;
    }
};

// O(n)

class Solution
{
public:
    bool request(int age_x, int age_y)
    {
        return !(age_y <= 0.5 * age_x + 7 || age_y > age_x);
    }
    int numFriendRequests(vector<int> &ages)
    {
        unordered_map<int, int> cnt;
        for (auto age : ages)
            cnt[age]++;

        int ans = 0;
        for (auto [age_x, cnt_x] : cnt)
            for (auto [age_y, cnt_y] : cnt)
                if (request(age_x, age_y))
                    ans += cnt_x * (cnt_y - (age_x == age_y ? 1 : 0));

        return ans;
    }
};