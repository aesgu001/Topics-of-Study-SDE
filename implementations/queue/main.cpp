#include "mylinkedqueue.h"
#include "myarrayqueue.h"

#include <assert.h>
#include <iostream>

void runLinkedQueueTests()
{
    bool nullCheck = false;
    MyLinkedQueue queue;

    std::cout << "running linked queue tests... ";

    // Empty queue
    // Expected:
    // queue = [10] -> [20] -> [30] -> *
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    assert(queue.empty() == false);

    // Queue of size 3
    // Expected:
    // queue = [30] -> *
    try
    {
        assert(queue.dequeue() == 10);
        assert(queue.dequeue() == 20);
        assert(queue.empty() == false);
    }
    catch(const std::invalid_argument &err)
    {
        nullCheck = true;
    }
    assert(nullCheck == false);

    std::cout << "PASSED!\n";
}

void runArrayQueueTests()
{
    bool rangeCheck = false;
    MyArrayQueue queue(5);

    std::cout << "running array queue tests... ";

    // Empty queue
    // Expected:
    // empty = false, full = true
    // queue = [3, 5, 7, 8, 11]
    try
    {
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);
        queue.enqueue(5);
        queue.enqueue(7);

        assert(queue.dequeue() == 1);
        assert(queue.dequeue() == 2);

        queue.enqueue(8);
        queue.enqueue(11);

        assert(queue.empty() == false);
        assert(queue.full() == true);
    }
    catch(const std::out_of_range &err)
    {
        rangeCheck = true;
    }
    assert(rangeCheck == false);

    std::cout << "PASSED!\n";
}

int main()
{
    runLinkedQueueTests();
    runArrayQueueTests();
    return 0;
}
