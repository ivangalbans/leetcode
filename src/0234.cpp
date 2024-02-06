// https://leetcode.com/problems/palindrome-linked-list/description/

// O(n) memory

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
    bool isPalindrome(ListNode *head)
    {
        stack<int> st;

        auto cur = head;
        while (cur)
        {
            st.push(cur->val);
            cur = cur->next;
        }

        cur = head;
        while (cur)
        {
            if (st.top() != cur->val)
                return false;
            st.pop();
            cur = cur->next;
        }

        return true;
    }
};

// O(1) memory

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
    ListNode *findMiddle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr, *cur = head, *next;

        while (cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode *head)
    {
        ListNode *middle = findMiddle(head);
        ListNode *rhead = reverseList(middle);

        while (rhead)
        {
            if (head->val != rhead->val)
                return false;
            head = head->next;
            rhead = rhead->next;
        }

        return true;
    }
};