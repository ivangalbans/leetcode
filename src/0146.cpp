// https://leetcode.com/problems/lru-cache/description/

class Node
{
public:
    Node *prev, *next;
    int key, val;

    Node(int key = -1, int val = -1, Node *prev = nullptr, Node *next = nullptr) : key(key), val(val), prev(prev), next(next) {}
};

class DoubleLinkedList
{
private:
    Node *front, *back;

public:
    int size;

    DoubleLinkedList() : size(0)
    {
        front = new Node();
        back = new Node();
        front->next = front->prev = back;
        back->next = back->prev = front;
    }

    void push_front(Node *val)
    {
        val->prev = front;
        val->next = front->next;
        front->next = front->next->prev = val;
        ++size;
    }

    Node *pop_back()
    {
        return erase(back->prev);
    }

    Node *erase(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        --size;
        return node;
    }
};

class LRUCache
{
private:
    int capacity;
    DoubleLinkedList cache;
    unordered_map<int, Node *> index;

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key)
    {
        if (!index.count(key))
            return -1;

        int val = index[key]->val;
        Node *temp = new Node(key, val);
        cache.push_front(temp);
        cache.erase(index[key]);
        index[key] = temp;

        return val;
    }

    void put(int key, int value)
    {
        Node *temp = new Node(key, value);
        cache.push_front(temp);

        if (index.count(key))
            cache.erase(index[key]);

        index[key] = temp;

        if (cache.size == capacity + 1)
            index.erase(cache.pop_back()->key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */