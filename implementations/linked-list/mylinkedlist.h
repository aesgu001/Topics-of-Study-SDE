# pragma once

// MyLinkedList class interface

#include <cstddef>
#include <stdexcept>

struct MyNode
{
    MyNode(int);
    MyNode();
    ~MyNode();

    int data;
    MyNode *next;
};

class MyLinkedList
{
    private:
    size_t _size;
    MyNode *_head;
    MyNode *_tail;
    static const char *_ERR_RANGE_CHECK;
    static const char *_ERR_NULL_PTR;

    public:
    MyLinkedList();
    ~MyLinkedList();
    // returns number of data elements in list
    size_t size() const;
    // returns true if empty
    bool empty() const;
    // returns the value of the item at index
    int value_at(size_t) const;
    // adds an item to the front of the list
    void push_front(int);
    // remove front item and return its value
    int pop_front();
    // adds an item at the end
    void push_back(int, bool);
    // removes end item and returns its value
    int pop_back();
    // get value of front item
    int front() const;
    // get value of back item
    int back(bool) const;
    // insert value at index, so current item at that index is pointed to by new item at index
    void insert(size_t, int);
    // removes node at given index
    void erase(size_t);
    // returns the value of the node at n-th position from the end of the list
    int value_n_from_end(size_t) const;
    // reverses the list
    void reverse();
    // removes the first item in the list with this value
    void remove_value(int);
};
