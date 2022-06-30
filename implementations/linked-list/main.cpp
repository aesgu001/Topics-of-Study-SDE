#include "mylinkedlist.h"

#include <assert.h>
#include <iostream>

void runNodeTest()
{
    MyNode node, node2(19);
    std::cout << "running node tests... ";

    // default node
    assert(node.data == 0);
    assert(node.next == nullptr);

    // node with data
    assert(node2.data == 19);
    assert(node2.next == nullptr);

    std::cout << "PASSED!\n"; 
}

void runFrontTest()
{
    bool rangeCheck = false;
    MyLinkedList list;

    std::cout << "running push front, pop front, and front tests... ";

    try
    {       
        // Empty list
        // Expected:
        // size = 1,
        // list = [5] -> *
        list.push_front(5);
        assert(list.size() == 1);
        assert(list.front() == 5);

        // List of size 1
        // Expected:
        // size = 2,
        // list = [10] -> [5] -> *
        list.push_front(10);
        assert(list.size() == 2);
        assert(list.front() == 10);

        // List of size 5
        // Expected:
        // size = 3,
        // list = [15] -> [10] -> [5] -> *
        list.push_front(15);
        list.push_front(20);
        list.push_front(5);

        list.pop_front();
        list.pop_front();

        assert(list.size() == 3);
        assert(list.front() == 15);
    }
    catch(const std::out_of_range &err)
    {
        rangeCheck = true;
    }
    assert(rangeCheck == false);

    std::cout << "PASSED!\n";
}

void runBackTest()
{
    bool rangeCheck = false, useTail = true;
    MyLinkedList list;

    std::cout << "running push back, pop back, and back tests... ";

    try
    {
        // Empty list
        // Expected:
        // size = 1,
        // list = [1] -> *
        list.push_back(1, useTail);

        assert(list.size() == 1);
        assert(list.back(useTail) == 1);

        // List of size 1
        // Expected:
        // size = 3,
        // list = [1] -> [5] -> [10] -> *
        list.push_back(5, useTail);
        list.push_back(10, useTail);

        assert(list.size() == 3);
        assert(list.back(useTail) == 10);

        // List of size 5
        // Expected:
        // size = 4,
        // list = [1] -> [5] -> [10] -> [8] -> *
        list.push_back(7, useTail);
        list.push_back(9, useTail);

        list.pop_back();
        list.pop_back();
        list.push_back(8, useTail);

        assert(list.size() == 4);
        assert(list.back(useTail) == 8);
    }
    catch(const std::out_of_range &err)
    {
        rangeCheck = true;
    }
    assert(rangeCheck == false);
    
    std::cout << "PASSED\n";
}

void runIndexTest()
{
    bool rangeCheck = false;
    MyLinkedList list;
    for (size_t i = 0; i < 5; ++i)
    {
        list.push_front(10 - 2 * i);
    }

    std::cout << "running index tests... ";

    try
    {
        assert(list.value_at(0) == 2);
        assert(list.value_at(2) == 6);

        assert(list.value_n_from_end(2) == 8);
        assert(list.value_n_from_end(5) == 2);
        assert(list.value_n_from_end(1) == list.value_at(list.size() - 1));
    }
    catch(const std::out_of_range &err)
    {
        rangeCheck = true;
    }
    assert(rangeCheck == false);

    std::cout << "PASSED!\n";
}

void runInsertEraseRemoveTest()
{
    bool rangeCheck = false;
    MyLinkedList list;
    list.push_front(5);
    list.push_front(0);
    list.push_front(-5);

    std::cout << "running insert, erase, and remove tests... ";

    // list of size 3
    try
    {
        // Expected:
        // size = 5
        // list = [-5] -> [-1] -> [0] -> [2] -> [5] -> *
        list.insert(1, -1);
        list.insert(3, 2);

        assert(list.size() == 5);
        assert(list.value_at(1) == -1);
        assert(list.value_at(3) == 2);

        // Expected:
        // size = 3
        // list = [-1] -> [2] -> [5] -> *
        list.erase(0);
        list.erase(1);

        assert(list.size() == 3);
        assert(list.value_at(0) == -1);
        assert(list.value_at(2) == 5);

        // Expected:
        // size = 2
        // list = [-1] -> [5] -> *
        list.remove_value(2);
        list.remove_value(2);

        assert(list.size() == 2);
        assert(list.value_at(1) == 5);
    }
    catch(const std::out_of_range &err)
    {
        rangeCheck = true;
    }
    assert(rangeCheck == false);

    std::cout << "PASSED!\n";
}

void runReverseTest()
{
    bool useTail = true;
    MyLinkedList list1;
    list1.push_front(1);
    list1.push_front(3);
    list1.push_front(5);

    MyLinkedList list2;
    list2.push_front(10);
    list2.push_front(8);
    list2.push_front(6);
    list2.push_front(4);
    list2.push_front(2);

    std::cout << "running reverse tests... ";

    // list of size 3
    // Expected:
    // list = [1] -> [3] -> [5] -> *
    list1.reverse();
    assert(list1.front() == 1);
    assert(list1.back(useTail) == 5);

    // list of size 5
    // Expected:
    // list = [2] -> [4] -> [6] -> [8] -> [10] -> *
    list2.reverse();
    list2.reverse();
    assert(list2.front() == 2);
    assert(list2.back(useTail) == 10);

    std::cout << "PASSED!\n";
}

void runMyLinkedListTests()
{
    std::cout << "running MyLinkedList tests...\n\n";

    runNodeTest();
    runFrontTest();
    runBackTest();
    runIndexTest();
    runInsertEraseRemoveTest();
    runReverseTest();

    std::cout << "\nall tests passed!\n";
}

int main()
{
    runMyLinkedListTests();
    return 0;
}
