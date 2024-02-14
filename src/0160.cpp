// https://leetcode.com/problems/intersection-of-two-linked-lists/description/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *nodeA = headA, *nodeB = headB;
        while (nodeA != nodeB)
        {
            nodeA = !nodeA ? headB : nodeA->next;
            nodeB = !nodeB ? headA : nodeB->next;
        }
        return nodeA;
    }
};