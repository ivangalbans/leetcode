// https://leetcode.com/problems/rotate-list/description/

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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
            return head;

        int n = 1;
        ListNode *end = head;
        while (end->next)
        {
            end = end->next;
            n++;
        }

        int pos = n - (k % n);

        if (pos == n)
            return head;

        ListNode *t = head;
        while (pos-- > 1)
            t = t->next;

        auto new_head = t->next;
        t->next = NULL;
        end->next = head;

        return new_head;
    }
};