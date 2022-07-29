// Hash Table class implementation

#include "myhashtable.h"

MyHashItem::MyHashItem(int k, int val) : key(k), value(val), removed(false)
{}

const char *MyHashTable::_ERR_RANGE_CHECK = "MyHashTable::_range_check";
const char *MyHashTable::_ERR_NULL_PTR = "MyHashTable::_null_pointer";

MyHashTable::MyHashTable(size_t capacity) : _size(0), _occupied(0), _capacity(4), _hashArray(nullptr)
{
    // Expand table to <= 2 * capacity
    while (this->_capacity < capacity)
    {
        this->_capacity *= 2;
    }

    // Initialize empty hash table
    this->_hashArray = new MyHashItem *[this->_capacity];
    for (size_t i = 0; i < this->_capacity; ++i)
    {
        *(this->_hashArray + i) = nullptr;
    }
}

MyHashTable::MyHashTable() : MyHashTable(0)
{}

MyHashTable::~MyHashTable()
{
    // Delete hash items
    for (size_t i = 0; i < this->_capacity; ++i)
    {
        if (this->_hashArray[i])
        {
            delete this->_hashArray[i];
            this->_hashArray[i] = nullptr;
        }
    }

    // Delete hash table
    delete[] this->_hashArray;
    this->_hashArray = nullptr;
}

void MyHashTable::add(int key, int value)
{
    if (this->_size == this->_capacity)
    {
        // Rehash items into a larger table
        this->resize(2 * this->_capacity);
    }

    size_t index = this->hashFunc(key);
    for (size_t i = 0; i < this->_capacity; ++i)
    {
        index = (index + i) % this->_capacity;
        // Occupy an empty slot or replace hash item's value
        if (!this->_hashArray[index])
        {
            this->_hashArray[index] = new MyHashItem(key, value);
            ++this->_size;
            ++this->_occupied;
            return;
        }
        else if (this->_hashArray[index]->key == key)
        {
            this->_hashArray[index]->value = value;
            if (this->_hashArray[index]->removed)
            {
                this->_hashArray[index]->removed = false;
                ++this->_occupied;
            }
            return;
        }
    }

    // Function should NOT move past this comment!
    throw(std::out_of_range(_ERR_RANGE_CHECK));
}

bool MyHashTable::exists(int key) const
{
    if (this->_size < 1 || this->_occupied < 1)
    {
        return false;
    }

    size_t index = this->hashFunc(key);
    for (size_t i = 0; i < this->_capacity; ++i)
    {
        index = (index + i) % this->_capacity;
        // Stop at a null hash item
        if (!this->_hashArray[index])
        {
            return false;
        }
        else if (this->_hashArray[index]->key == key)
        {
            // Return true if hash item is not yet removed
            return !this->_hashArray[index]->removed;
        }
    }

    return false;
}

int MyHashTable::get(int key) const
{
    if (this->_size < 1 || this->_occupied < 1)
    {
        throw(std::out_of_range(_ERR_RANGE_CHECK));
    }

    size_t index = this->hashFunc(key);
    for (size_t i = 0; i < this->_capacity; ++i)
    {
        index = (index + i) % this->_capacity;
        // Stop at a null hash item
        if (!this->_hashArray[index])
        {
            throw(std::invalid_argument(_ERR_NULL_PTR));
        }
        else if (this->_hashArray[index]->key == key)
        {
            if (this->_hashArray[index]->removed)
            {
                throw(std::invalid_argument(_ERR_NULL_PTR));
            }

            return this->_hashArray[index]->value;
        }
    }

    throw(std::out_of_range(_ERR_RANGE_CHECK));
}

bool MyHashTable::remove(int key)
{
    if (this->_size < 1 || this->_occupied < 1)
    {
        return false;
    }

    size_t index = this->hashFunc(key);
    for (size_t i = 0; i < this->_capacity; ++i)
    {
        index = (index + i) % this->_capacity;
        // Stop at a null hash item
        if (!this->_hashArray[index])
        {
            return false;
        }
        else if (this->_hashArray[index]->key == key)
        {
            if (this->_hashArray[index]->removed)
            {
                return false;
            }

            // Replace hash item with tombstone
            this->_hashArray[index]->removed = true;

            // Reduce occupied; resize if needed
            --this->_occupied;
            if (this->_capacity > 4 && 4 * this->_occupied <= this->_capacity)
            {
                this->resize(this->_capacity / 2);
            }

            return true;
        }
    }

    return false;
}

size_t MyHashTable::hashFunc(int key)
{
    // Return absolute value of key
    return static_cast<size_t>((key < 0)? -1 * key : key);
}

void MyHashTable::resize(size_t capacity2)
{
    size_t size2 = 0;
    MyHashItem **hashArray2 = new MyHashItem *[capacity2];
    // Initialize new empty hash table
    for (size_t i = 0; i < capacity2; ++i)
    {
        hashArray2[i] = nullptr;
    }

    for (size_t i = 0; i < this->_capacity; ++i)
    {
        if (this->_hashArray[i])
        {
            // Copy occupied hash items
            if (!this->_hashArray[i]->removed)
            {
                size_t index = hashFunc(this->_hashArray[i]->key);
                for (size_t j = 0; j < capacity2; ++j)
                {
                    index = (index + j) % capacity2;               
                    if (!hashArray2[index])
                    {
                        hashArray2[index] = new MyHashItem(this->_hashArray[i]->key,
                            this->_hashArray[i]->value);
                        ++size2;
                        break;
                    }
                }
            }

            // Delete hash item
            delete this->_hashArray[i];
            this->_hashArray[i] = nullptr;
        }
    }

    // Update size, capacity, and hash table
    this->_size = size2;
    this->_capacity = capacity2;
    delete[] this->_hashArray;
    this->_hashArray = hashArray2;
}
