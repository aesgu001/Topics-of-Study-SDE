#include "myvector.h"

#include <assert.h>
#include <iostream>

void runMemAllocTest()
{
    MyVector testV;
    std::cout << "running memory allocation, size, and capacity tests... ";

    // empty vector (size 0)
    assert(testV.size() == 0);
    assert(testV.capacity() == 16);
    assert(testV.is_empty() == true);

    // vector of size 10
    testV = MyVector(10);
    assert(testV.size() == 10);
    assert(testV.capacity() == 16);
    assert(testV.is_empty() == false);

    // vector of size > 16
    testV = MyVector(17);
    assert(testV.size() == 17);
    assert(testV.capacity() == 32);
    assert(testV.is_empty() == false);

    std::cout << "PASSED!\n";
}

void runIndexUpdateTest()
{
    bool rangeCheck = false;
    MyVector testV(10, 5);

    std::cout << "running index and update tests... ";

    // vector of size 10
    try
    {
        // Expected:
        // arr = [5, 5, 10, 5, 15, 5, 20, 5, 25, 5]
        for (size_t i = 0; i < testV.size(); ++i)
        {
            if (i % 2 == 0)
            {
                testV.at(i) = 5 * (i / 2) + 5;
            }
        }

        assert(testV.at(0) == 5);
        assert(testV.at(1) == 5);
        assert(testV.at(4) == 15);
        assert(testV.at(8) == 25);
    }
    catch(const std::out_of_range &err)
    {
        rangeCheck = true;
    }
    assert(rangeCheck == false);

    // range check
    try
    {
        // Expected:
        // out of range error
        int val = testV.at(100);
        std::cout << val << '\n';
    }
    catch(const std::out_of_range &err)
    {
        rangeCheck = true;
    }
    assert(rangeCheck == true);

    rangeCheck = false;
    try
    {
        // Expected:
        // out of range error
        testV.at(10) = 30;
    }
    catch(const std::out_of_range &err)
    {
        rangeCheck = true;
    }
    assert(rangeCheck == true);    

    std::cout << "PASSED!\n";
}

void runInsertTest()
{
    bool rangeCheck = false;
    MyVector testV(5, 1);

    std::cout << "running insert, push, and prepend tests... ";

    // vector of size 5
    try
    {
        // Expected:
        // size = 10, capacity = 16
        // arr = [20, 1, 1, 2, 1, 1, 4, 1, 5, 10]

        testV.insert(2, 2);
        testV.insert(5, 4);
        testV.prepend(20);
        testV.push(5);
        testV.push(10);

        assert(testV.size() == 10);
        assert(testV.capacity() == 16);
        
        assert(testV.at(0) == 20);
        assert(testV.at(3) == 2);
        assert(testV.at(6) == 4);
        assert(testV.at(8) == 5);
        assert(testV.at(testV.size() - 1) == 10);
    }
    catch(const std::out_of_range &err)
    {
        rangeCheck = true;
    }
    assert(rangeCheck == false);

    // expand vector
    testV = MyVector(16);
    try
    {
        // Expected:
        // size = 17, capacity = 32
        // arr [0, 0, ..., 0, 16]
        testV.push(16);
        
        assert(testV.size() == 17);
        assert(testV.capacity() == 32);
        assert(testV.at(testV.size() - 1) == 16);
    }
    catch(const std::out_of_range &err)
    {
        rangeCheck = true;
    }
    assert(rangeCheck == false);
    
    std::cout << "PASSED!\n";
}

void runDeleteTest()
{
    bool rangeCheck = false;
    MyVector testV(15);

    std::cout << "running pop and delete_at tests... ";

    // vector of size 15
    try
    {
        // Expected:
        // size = 11, capacity = 16
        // arr = [1, 2, 4, 5, 6, 7, 8, 9, 11, 12, 13]

        int val1 = 0, val2 = 0;

        for (size_t i = 0; i < testV.size(); ++i)
        {
            testV.at(i) = i + 1;
        }
        val1 = testV.pop();
        val2 = testV.pop();
        testV.delete_at(2);
        testV.delete_at(8);

        assert(testV.size() == 11);
        assert(testV.capacity() == 16);

        assert(val1 == 15);
        assert(val2 == 14);
        assert(testV.at(2) == 4);
        assert(testV.at(8) == 11);
        assert(testV.at(testV.size() - 1) == 13);
    }
    catch(const std::out_of_range &err)
    {
        rangeCheck = true;
    }
    assert(rangeCheck == false);

    // reduce vector capacity
    testV = MyVector(5);
    try
    {
        // Expected:
        // size = 4, capacity = 8
        // arr = [0, 0, 0, 0]
        testV.pop();

        assert(testV.size() == 4);
        assert(testV.capacity() == 8);
    }
    catch(const std::out_of_range &err)
    {
        rangeCheck = true;
    }
    assert(rangeCheck == false);  

    std::cout << "PASSED!\n";
}

void runRemoveTest()
{
    MyVector testV;
    std::cout << "running remove tests... ";

    // vector of size 8
    testV.push(10);
    testV.push(20);
    testV.push(10);
    testV.push(30);
    testV.push(10);
    testV.push(40);
    testV.push(10);
    testV.push(50);

    // Expected:
    // size = 4, capacity = 8
    // arr = [20, 30, 40, 50]
    testV.remove(10);

    assert(testV.size() == 4);
    assert(testV.capacity() == 8);

    for (size_t i = 0; i < testV.size(); ++i)
    {
        assert(testV.at(i) != 10);
    }

    std::cout << "PASSED!\n";
}

void runFindTest()
{
    MyVector testV;
    std::cout << "running find tests... ";

    // vector of size 4
    testV.push(1);
    testV.push(2);
    testV.push(1);
    testV.push(8);

    assert(testV.find(2) == 1);
    assert(testV.find(1) == 0);
    assert(testV.find(4) == -1);

    std::cout << "PASSED!\n";
}

void runMyVectorTests()
{
    std::cout << "running MyVector tests...\n\n";

    // run memory allocation, size, and capacity test
    runMemAllocTest();
    // run index and update test
    runIndexUpdateTest();
    // run insert, push, and prepend test
    runInsertTest();
    // run pop and delete_at test
    runDeleteTest();
    // run remove test
    runRemoveTest();
    // run find test
    runFindTest();

    std::cout << "\nall tests passed!\n";
}

int main()
{
    runMyVectorTests();
    return 0;
}