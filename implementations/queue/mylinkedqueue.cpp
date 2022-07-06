#include "mylinkedqueue.h"

// Linked List Queue class implementation

MyNode::MyNode(int val) : data(val), next(nullptr)
{}

MyNode::MyNode() : MyNode(0)
{}

MyNode::~MyNode()
{}

const char *MyLinkedQueue::_ERR_NULL_PTR = "MyLinkedQueue::_null_pointer";

MyLinkedQueue::MyLinkedQueue() : _head(nullptr), _tail(nullptr)
{}

MyLinkedQueue::~MyLinkedQueue()
{
    // Move tail to null
    this->_tail = nullptr;

    // Delete all nodes starting from head
    while (this->_head)
    {
        MyNode *node = this->_head;
        this->_head = this->_head->next;
        delete node;
    }
}

void MyLinkedQueue::enqueue(int val)
{
    MyNode *node = new MyNode(val);
    // Move tail and head to node if empty
    if (!this->_tail)
    {
        this->_head = this->_tail = node;
    }
    // Move tail to node
    else
    {
        this->_tail->next = node;
        this->_tail = node;
    }
}

int MyLinkedQueue::dequeue()
{
    int val = 0;
    MyNode *node = this->_head;

    if (!this->_head)
    {
        throw(std::invalid_argument(_ERR_NULL_PTR));
    }

    // Get front node data
    val = node->data;

    // Move head to next node
    this->_head = this->_head->next;

    // Move tail to null if empty
    if (!this->_head)
    {
        this->_tail = nullptr;
    }

    // Delete front node and return its data
    delete node;
    return val;
}

bool MyLinkedQueue::empty() const
{
    return !this->_head;
}
