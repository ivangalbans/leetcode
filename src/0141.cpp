// https://leetcode.com/problems/linked-list-cycle/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        do
        {
            if (slow == NULL || fast == NULL || fast->next == NULL)
                return false;

            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);

        return true;
    }
};