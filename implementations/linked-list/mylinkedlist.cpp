#include "mylinkedlist.h"

// MyLinkedList class implementation

MyNode::MyNode(int val) : data(val), next(nullptr)
{}

MyNode::MyNode() : MyNode(0)
{}

MyNode::~MyNode()
{}

const char *MyLinkedList::_ERR_RANGE_CHECK = "MyLinkedList::_range_check";
const char *MyLinkedList::_ERR_NULL_PTR = "MyLinkedList::_null_pointer";

MyLinkedList::MyLinkedList() : _size(0), _head(nullptr), _tail(nullptr)
{}

MyLinkedList::~MyLinkedList()
{
    // Set tail to null
    this->_tail = nullptr;

    // Delete all nodes starting from head
    while (this->_head)
    {
        MyNode *node = this->_head;
        this->_head = this->_head->next;
        delete node;
    }
}

size_t MyLinkedList::size() const
{
    return this->_size;
}

bool MyLinkedList::empty() const
{
    return this->_size < 1;
}

int MyLinkedList::value_at(size_t index) const
{
    MyNode *node = this->_head;
    if (index >= this->_size)
    {
        throw(std::out_of_range(_ERR_RANGE_CHECK));
    }

    // Return node data at index
    for (size_t i = 0; node && i < index; ++i)
    {
        node = node->next;
    }
    if (!node)
    {
        throw(std::invalid_argument(_ERR_NULL_PTR));
    }
    return node->data;
}

void MyLinkedList::push_front(int val)
{
    MyNode *node = new MyNode(val);
    node->next = this->_head;

    // Move head to new node
    ++this->_size;
    this->_head = node;

    // Move tail to head if empty
    if (!this->_tail)
    {
        this->_tail = this->_head;
    }
}

int MyLinkedList::pop_front()
{
    int val = 0;
    MyNode *node = this->_head;

    if (this->_size < 1)
    {
        throw(std::out_of_range(_ERR_RANGE_CHECK));
    }

    // Get data from front (head)
    if (!node)
    {
        throw(std::invalid_argument(_ERR_NULL_PTR));
    }
    val = node->data;

    // Move head to next node
    --this->_size;
    this->_head = this->_head->next;

    // Set tail to null if empty
    if (!this->_head)
    {
        this->_tail = nullptr;
    }

    // Delete front node and return its data
    delete node;
    return val;
}

void MyLinkedList::push_back(int val, bool useTail)
{
    MyNode *node = new MyNode(val);
    MyNode *last = this->_head;

    if (useTail)
    {
        last = this->_tail;
    }
    else
    {
        // Go to last node (i.e. node w/o next)
        while (last && last->next)
        {
            last = last->next;
        }
    }

    // Move head and tail to node if empty
    ++this->_size;
    if (!last)
    {
        this->_head = this->_tail = node;
    }
    // Move tail to new node
    else
    {
        last->next = node;
        this->_tail = node;
    }
}

int MyLinkedList::pop_back()
{
    int val = 0;
    MyNode *last = this->_head, *prev = nullptr;

    if (this->_size < 1)
    {
        throw(std::out_of_range(_ERR_RANGE_CHECK));
    }

    // Get last and prev nodes; read last node's data
    while (last && last->next)
    {
        prev = last;
        last = last->next;
    }
    if (!last)
    {
        throw(std::invalid_argument(_ERR_NULL_PTR));
    }
    val = last->data;
    
    // Set head and tail to null if empty
    --this->_size;
    if (!prev)
    {
        this->_head = this->_tail = nullptr;
    }
    // Move tail to prev node
    else
    {
        prev->next = nullptr;
        this->_tail = prev;
    }

    // Delete last node and return its data
    delete last;
    return val;
}

int MyLinkedList::front() const
{
    if (this->_size < 1)
    {
        throw(std::out_of_range(_ERR_RANGE_CHECK));
    }
    // Return front node data (head)
    else if (!this->_head)
    {
        throw(std::invalid_argument(_ERR_NULL_PTR));
    }
    return this->_head->data;
}

int MyLinkedList::back(bool useTail) const
{
    MyNode *last = this->_head;
    if (this->_size < 1)
    {
        throw(std::out_of_range(_ERR_RANGE_CHECK));
    }
    else if (useTail)
    {
        // Return tail node data
        if (!this->_tail)
        {
            throw(std::invalid_argument(_ERR_NULL_PTR));
        }
        return this->_tail->data;
    }

    // Return last node data
    while (last && last->next)
    {
        last = last->next;
    }
    if (!last)
    {
        throw(std::invalid_argument(_ERR_NULL_PTR));
    }
    return last->data;
}

void MyLinkedList::insert(size_t index, int val)
{
    MyNode *node = this->_head, *prev = nullptr, *newNode = nullptr;
    if (index < 1)
    {
        this->push_front(val);
        return;
    }
    else if (index == this->_size)
    {
        this->push_back(val, true);
        return;
    }
    else if (index > this->_size)
    {
        throw(std::out_of_range(_ERR_RANGE_CHECK));
    }

    // Get node at index and its previous node
    for (size_t i = 0; node && i < index; ++i)
    {
        prev = node;
        node = node->next;
    }
    if (!node || !prev)
    {
        throw(std::invalid_argument(_ERR_NULL_PTR));
    }

    // Add new node to index and shift node to the right
    ++this->_size;
    newNode = new MyNode(val);
    newNode->next = node;
    prev->next = newNode;
}

void MyLinkedList::erase(size_t index)
{
    MyNode *node = this->_head, *prev = nullptr;
    if (index < 1)
    {
        this->pop_front();
        return;
    }
    else if (index == this->_size - 1)
    {
        this->pop_back();
        return;
    }
    else if (index >= this->_size)
    {
        throw(std::out_of_range(_ERR_RANGE_CHECK));
    }

    // Get node and prev node at index
    for (size_t i = 0; node && i < index; ++i)
    {
        prev = node;
        node = node->next;
    }
    if (!node || !prev)
    {
        throw(std::invalid_argument(_ERR_NULL_PTR));
    }

    // Move prev->next to next node
    --this->_size;
    prev->next = node->next;

    // Delete node
    delete node;
}

int MyLinkedList::value_n_from_end(size_t n) const
{
    if (n < 1 || n > this->_size)
    {
        throw(std::out_of_range(_ERR_RANGE_CHECK));
    }

    // Return node data at n starting from end of list
    return this->value_at(this->_size - n);
}

void MyLinkedList::reverse()
{
    MyNode *current = this->_head, *next = nullptr, *prev = nullptr;
    // Move tail to head
    this->_tail = this->_head;
    // Move current->next to prev for each node
    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    // Move head to prev (or tail)
    this->_head = prev;
}

void MyLinkedList::remove_value(int val)
{
    // Search for first node with val data and delete it
    for (MyNode *node = this->_head, *prev = nullptr; node; prev = node, node = node->next)
    {
        if (node->data == val)
        {
            --this->_size;
            // Move head to next node
            if (node == this->_head)
            {
                this->_head = node->next;
            }
            // Move tail to prev node
            if (node == this->_tail)
            {
                this->_tail = prev;
            }
            // Move prev->next to next node
            if (prev)
            {
                prev->next = node->next;
            }

            // Delete node
            delete node;
            return;
        }
    }
}
