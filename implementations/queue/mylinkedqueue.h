# pragma once

// Linked List Queue class interface

#include <stdexcept>

struct MyNode
{
    MyNode(int);
    MyNode();
    ~MyNode();

    int data;
    MyNode *next;
};

class MyLinkedQueue
{
    private:
    MyNode *_head;
    MyNode *_tail;
    static const char *_ERR_NULL_PTR;

    public:
    MyLinkedQueue();
    ~MyLinkedQueue();

    // adds value at position tail
    void enqueue(int);
    // returns value and removes least recently added element (front)
    int dequeue();
    bool empty() const;

    // cost:
    // enqueue: O(1)
    // dequeue: O(1)
    // empty: O(1)
};
