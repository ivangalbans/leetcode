// https://leetcode.com/problems/copy-list-with-random-pointer/description/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{

private:
    unordered_map<Node *, Node *> memory;

public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;

        if (memory[head])
            return memory[head];

        Node *head_copy = new Node(head->val);
        memory[head] = head_copy;
        head_copy->next = copyRandomList(head->next);
        head_copy->random = copyRandomList(head->random);
        return head_copy;
    }
};