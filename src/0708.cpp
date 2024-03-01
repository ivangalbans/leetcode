// https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution
{
public:
    Node *insert(Node *head, int insertVal)
    {
        Node *newNode = new Node(insertVal);

        if (!head)
        {
            newNode->next = newNode;
            return newNode;
        }

        Node *node = head;

        while (node->val <= node->next->val && node->next != head)
            node = node->next;

        Node *start = node->next;
        if (start->val > newNode->val)
        {
            node->next = newNode;
            newNode->next = start;
        }
        else
        {
            node = start;
            while (node->next->val < newNode->val && node->next != start)
                node = node->next;
            newNode->next = node->next;
            node->next = newNode;
        }

        return head;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution
{
public:
    bool index_to_insert(int prev, int next, int val)
    {
        return (prev <= val && val <= next) || // 1 _3_ 9
               (prev > next && val > prev) ||  // 9 _10_ 3
               (prev > next && val < next);    // // 9 _1_ 3
    }

    Node *insert(Node *head, int insertVal)
    {
        if (!head)
        {
            Node *newNode = new Node(insertVal);
            newNode->next = newNode;
            return newNode;
        }

        Node *prev = head, *next = head->next;
        while (next != head && !index_to_insert(prev->val, next->val, insertVal))
        {
            prev = prev->next;
            next = next->next;
        }
        prev->next = new Node(insertVal, next);

        return head;
    }
};