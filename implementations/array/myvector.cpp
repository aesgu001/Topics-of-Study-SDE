#include "myvector.h"

// MyVector class implementation

const char *MyVector::_ERR_RANGE_CHECK = "MyVector::_range_check";

MyVector::MyVector(size_t size, int val) : _size(size), _capacity(16)
{
    // Increase capacity until >= size
    while (this->_capacity < this->_size)
    {
        this->_capacity *= 2;
    }

    // Allocate memory by capacity
    this->_arr = new int[this->_capacity];
    // Assign value to each index < size
    for (size_t i = 0; i < this->_size; ++i)
    {
        *(this->_arr + i) = val;
    }
}

MyVector::MyVector(size_t size) : MyVector(size, 0)
{}

MyVector::MyVector() : MyVector(0, 0)
{}

MyVector::MyVector(const MyVector &rhs) : _size(rhs._size), _capacity(rhs._capacity)
{
    // Copy rhs array
    this->copy_array(rhs._arr, rhs._size, rhs._capacity);
}

MyVector &MyVector::operator=(const MyVector &rhs)
{
    // Skip self-assignment
    if (this != &rhs)
    {
        this->_size = rhs._size;
        this->_capacity = rhs._capacity;

        // Copy rhs array
        this->copy_array(rhs._arr, rhs._size, rhs._capacity);
    }

    return *this;
}

MyVector::~MyVector()
{
    delete[] this->_arr;
    this->_arr = nullptr;
}

const size_t &MyVector::size() const
{
    return this->_size;
}

const size_t &MyVector::capacity() const
{
    return this->_capacity;
}

bool MyVector::is_empty() const
{
    return this->_size < 1;
}

const int &MyVector::at(size_t index) const
{
    // Check if index is within range
    if (index >= this->_size)
    {
        throw(std::out_of_range(_ERR_RANGE_CHECK));
    }

    // Return item at index
    return *(this->_arr + index);
}

int &MyVector::at(size_t index)
{
    if (index >= this->_size)
    {
        throw(std::out_of_range(_ERR_RANGE_CHECK));
    }

    // Return reference to index
    return *(this->_arr + index);
}

void MyVector::push(int val)
{
    // Insert val at end of vector
    this->insert(this->_size, val);
}

void MyVector::insert(size_t index, int val)
{
    // Check if index is within range
    if (index > this->_size)
    {
        throw(std::out_of_range(_ERR_RANGE_CHECK));
    }
    // Expand array by 2 * capacity
    else if (this->_size >= this->_capacity)
    {
        this->resize(2 * this->_capacity);
    }

    // Shift all elements to the right up to index 
    // increment size
    for (size_t i = this->_size++; i > index; --i)
    {
        *(this->_arr + i) = *(this->_arr + i - 1);
    }
    // Add val to index
    *(this->_arr + index) = val;
}

void MyVector::prepend(int val)
{
    // Insert val at position 0
    this->insert(0, val);
}

int MyVector::pop()
{
    // Get last element and let delete handle removal
    int val = this->at(this->_size - 1);
    this->delete_at(this->_size - 1);

    return val;
}

void MyVector::delete_at(size_t index)
{
    // Check for range
    if (index >= this->_size)
    {
        throw(std::out_of_range(_ERR_RANGE_CHECK));
    }

    // Shift all elements to the left starting from index
    for (size_t i = index; i < this->_size - 1; ++i)
    {
        *(this->_arr + i) = *(this->_arr + i + 1);
    }
    // Decrement size; reduce capacity by half if >= 4 * size
    --this->_size;
    if (this->_capacity > 4 && 4 * this->_size <= this->_capacity)
    {
        this->resize(this->_capacity / 2);
    }
}

void MyVector::remove(int val)
{
    size_t size = this->_size;
    // Reduce size if value found
    // Otherwise shift element to the left
    for (size_t i = 0, j = 0; j < this->_size; ++j)
    {
        if (*(this->_arr + j) != val)
        {
            *(this->_arr + i++) = *(this->_arr + j);
        }
        else
        {
            --size;
        }
    }

    // Update size, and reduce capacity if needed
    this->_size = size;
    if (this->_capacity > 4 && 4 * this->_size <= this->_capacity)
    {
        this->resize(this->_capacity / 2);
    }
}

int MyVector::find(int val) const
{
    // Return index with matching value
    for (size_t i = 0; i < this->_size; ++i)
    {
        if (*(this->_arr + i) == val)
        {
            return static_cast<int>(i);
        }
    }

    // No such value found
    return -1;
}

void MyVector::resize(size_t capacity)
{
    int *arr = this->_arr;
    this->_capacity = capacity;
    this->_arr = nullptr;
    // copy arr
    this->copy_array(arr, this->_size, capacity);
    // delete arr
    delete[] arr;
}

void MyVector::copy_array(const int *arr, size_t size, size_t capacity)
{
    // Reallocate memory by arr capacity
    if (this->_arr)
    {
        delete[] this->_arr;
    }
    this->_arr = new int[capacity];
    // Assign arr values to each index
    for (size_t i = 0; i < size; ++i)
    {
        *(this->_arr + i) = *(arr + i);
    }
}
