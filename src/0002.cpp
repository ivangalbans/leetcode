// https://leetcode.com/problems/add-two-numbers/

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int carry)
    {

        if (l1 == nullptr && l2 == nullptr && carry == 0)
            return nullptr;

        int d1 = l1 != nullptr ? l1->val : 0;
        int d2 = l2 != nullptr ? l2->val : 0;
        int num = d1 + d2 + carry;
        int d = num % 10;

        return new ListNode(d, addTwoNumbers(l1 != nullptr ? l1->next : nullptr, l2 != nullptr ? l2->next : nullptr, num / 10));
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        return addTwoNumbers(l1, l2, 0);
    }
};