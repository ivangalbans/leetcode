// https://leetcode.com/problems/design-linked-list/description/

class MyLinkedList
{
private:
    class Node
    {
    public:
        Node *prev, *next;
        int val;

        Node() : val(-1), prev(nullptr), next(nullptr) {}

        Node(int val, Node *prev, Node *next) : val(val), prev(prev), next(next) {}
    };

    Node *front, *back; // dummy nodes

    Node *get_node(int index)
    {

        if (index >= size)
            return back;

        Node *it = front->next;
        while (index)
        {
            it = it->next;
            --index;
        }

        return it;
    }

public:
    int size;

    MyLinkedList() : size(0)
    {
        front = new Node();
        back = new Node();

        front->next = front->prev = back;
        back->next = back->prev = front;
    }

    int get(int index)
    {
        return get_node(index)->val;
    }

    void addAtHead(int val)
    {
        addAtIndex(0, val);
    }

    void addAtTail(int val)
    {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val)
    {
        if (index > size)
            return;

        Node *next = get_node(index);
        Node *prev = next->prev;
        Node *cur = new Node(val, prev, next);
        prev->next = cur;
        next->prev = cur;
        ++size;
    }

    void deleteAtIndex(int index)
    {
        if (index >= size)
            return;

        Node *cur = get_node(index);
        Node *prev = cur->prev;
        Node *next = cur->next;
        prev->next = next;
        next->prev = prev;
        --size;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */