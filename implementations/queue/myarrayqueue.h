#pragma once

// Circular Array Queue class interface

#include <cstddef>
#include <stdexcept>

class MyArrayQueue
{
    private:
    int _read;
    int _write;
    size_t _size;
    int *_arr;
    static const char *_ERR_RANGE_CHECK;

    public:
    MyArrayQueue(size_t);
    MyArrayQueue();
    ~MyArrayQueue();

    // adds item at end of available storage
    void enqueue(int);
    // returns value and removes least recently added element
    int dequeue();
    bool empty() const;
    bool full() const;

    // cost:
    // enqueue: O(1)
    // dequeue: O(1)
    // empty: O(1)
    // full: O(1)
};