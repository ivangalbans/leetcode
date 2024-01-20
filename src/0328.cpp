// https://leetcode.com/problems/odd-even-linked-list/description/

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
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *even_head = head->next;
        ListNode *last_odd = head;
        ListNode *odd = head, *even = even_head;
        while (odd && even)
        {
            if (odd->next)
                odd->next = odd->next->next;
            if (even->next)
                even->next = even->next->next;
            last_odd = odd;
            odd = odd->next;
            even = even->next;
        }

        if (!odd)
            last_odd->next = even_head;
        else
            odd->next = even_head;

        return head;
    }
};