#pragma once

// Hash Table class interface

#include <cstddef>
#include <stdexcept>

struct MyHashItem
{
    int key;
    int value;
    bool removed;
    MyHashItem(int, int);
};

class MyHashTable
{
    private:
    // # of hash items
    size_t _size;
    // size - # hash tombstones
    size_t _occupied;
    size_t _capacity;
    MyHashItem **_hashArray;
    static const char *_ERR_RANGE_CHECK;
    static const char *_ERR_NULL_PTR;

    public:
    MyHashTable(size_t);
    MyHashTable();
    ~MyHashTable();

    // if key already exists, update value
    void add(int, int);
    bool exists(int) const;
    int get(int) const;
    bool remove(int);

    private:
    static size_t hashFunc(int);
    void resize(size_t);
};
