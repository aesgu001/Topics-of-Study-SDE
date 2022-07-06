#include "myarrayqueue.h"

// Circular Array Queue class implementation

const char *MyArrayQueue::_ERR_RANGE_CHECK = "MyArrayQueue::_range_check";

MyArrayQueue::MyArrayQueue(size_t size) : _read(-1), _write(-1), _size(size), _arr(nullptr)
{
    // Lowest size: 4
    if (this->_size < 4)
    {
        this->_size = 4;
    }

    // Allocate array from memory
    this->_arr = new int[this->_size];
}

MyArrayQueue::MyArrayQueue() : MyArrayQueue(4)
{}

MyArrayQueue::~MyArrayQueue()
{
    delete[] this->_arr;
    this->_arr = nullptr;
}

void MyArrayQueue::enqueue(int val)
{
    if (this->empty())
    {
        this->_read = this->_write = 0;
    }
    else if (this->full())
    {
        throw(std::out_of_range(_ERR_RANGE_CHECK));
    }
    else
    {
        this->_write = (this->_write + 1) % this->_size;
    }

    // Add element to write end of queue
    this->_arr[this->_write] = val;
}

int MyArrayQueue::dequeue()
{
    int val = 0;
    if (this->empty())
    {
        throw(std::out_of_range(_ERR_RANGE_CHECK));
    }

    // Get front element and update read end
    val = this->_arr[this->_read];
    this->_read = (this->_read + 1) % this->_size;
    // Reset if read = write
    if (this->_read == this->_write)
    {
        this->_read = this->_write = -1;
    }

    return val;
}

bool MyArrayQueue::empty() const
{
    return this->_read < 0;
}

bool MyArrayQueue::full() const
{
    return (this->_read == 0 && this->_write == static_cast<int>(this->_size - 1)) ||
        (this->_write == this->_read - 1);
}
