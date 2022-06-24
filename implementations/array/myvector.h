# pragma once

// MyVector class interface

#include <cstddef>
#include <stdexcept>

class MyVector
{
    private:
    size_t _size;
    size_t _capacity;
    int *_arr;
    static const char *_ERR_RANGE_CHECK;

    public:
    // New raw data array with allocated memory
    // start with capacity 16, or if starting number is greater, use power of 2 - 16, 32, 64, 128 
    MyVector(size_t, int);
    MyVector(size_t);
    MyVector();
    MyVector(const MyVector&);
    MyVector &operator=(const MyVector&);
    ~MyVector();

    // number of items
    const size_t &size() const;
    // number of items it can hold
    const size_t &capacity() const;
    bool is_empty() const;
    // returns item at given index, error if index out of bounds
    const int &at(size_t) const;
    int &at(size_t);
    void push(int);
    // inserts item at index, shifts that index's value and trailing elements to the right
    void insert(size_t, int);
    // inserts at index 0
    void prepend(int);
    // remove from end, return value
    int pop();
    // delete item at index, shifting all trailing elements left
    void delete_at(size_t);
    // looks for value and remove index holding it (even if in multiple places)
    void remove(int);
    // looks for value and returns first index with that value, -1 if not found
    int find(int) const;

    private:
    // when you reach capacity, resize to double the size
    // wehn popping an item, if size is 1/4 of capacity, resize to half
    void resize(size_t);
    // makes a copy of arr
    void copy_array(const int *, size_t, size_t);

    // Target time complexity:
    // O(1) to add/remove at end (amortized for allocations for more space), index, or update
    // O(N) to insert/remove elsewhere

    // Target space complexity:
    // contiguous in memory, so proximity helps performance
    // space needed = array capacity, which is O(N)
};
