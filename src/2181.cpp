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
class Solution {
public:
  ListNode *mergeNodes(ListNode *head) {

    if (!head->next)
      return nullptr;

    ListNode *it;
    for (it = head->next; it->val != 0; it = it->next)
      head->val += it->val;
    head->next = mergeNodes(it);

    return head;
    ;
  }
};
