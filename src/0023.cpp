// https://leetcode.com/problems/merge-k-sorted-lists/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeKLists(priority_queue<pair<int, ListNode *>> &pq)
    {
        if (pq.empty())
            return nullptr;

        auto [val, node] = pq.top();
        pq.pop();
        if (node->next)
            pq.push({-node->next->val, node->next});

        return new ListNode(-val, mergeKLists(pq));
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<pair<int, ListNode *>> pq;
        for (auto node : lists)
            if (node)
                pq.push({-node->val, node});
        return mergeKLists(pq);
    }
};

// Wihout Priority Queue (TLE in the last case)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        if (l1->val <= l2->val)
            return new ListNode(l1->val, mergeTwoLists(l1->next, l2));
        return new ListNode(l2->val, mergeTwoLists(l1, l2->next));
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return nullptr;

        ListNode *cur = lists[0];
        for (int i = 1; i < lists.size(); ++i)
            cur = mergeTwoLists(cur, lists[i]);

        return cur;
    }
};