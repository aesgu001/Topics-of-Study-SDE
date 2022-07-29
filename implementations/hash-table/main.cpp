#include "myhashtable.h"

#include <assert.h>
#include <iostream>

void runHiTest()
{
    MyHashItem item(-1, -1);
    std::cout << "running hash item tests... ";

    assert(item.removed == false);

    std::cout << "PASSED!\n";
}

void runHtAddSearchRemoveTests()
{
    bool rangeCheck = false;
    bool validCheck = false;
    MyHashTable hashTable;

    std::cout << "Running add, search and remove tests... ";

    // Empty hash table
    // Expected:
    // table <- [*][*][(10, 3)][(-10, -5)][(4, 20)][(-5, 4)][*][*]
    try
    {
        hashTable.add(10, 5);
        hashTable.add(-10, -5);
        hashTable.add(-5, 4);
        hashTable.add(4, 20);
        hashTable.add(10, 3);

        assert(hashTable.exists(10) && hashTable.exists(-10) && hashTable.exists(4)
            && hashTable.exists(-5));
        assert(hashTable.get(10) == 3);
        assert(hashTable.get(-10) == -5);
        assert(hashTable.get(-5) == 4);
        assert(hashTable.get(4) == 20);
    }
    catch(const std::out_of_range &err)
    {
        rangeCheck = true;
    }
    catch(const std::invalid_argument &err)
    {
        validCheck = true;
    }
    assert(!rangeCheck && !validCheck);

    // Table of size 8
    // Expected:
    // table <- [*][(-5, 4)][(10, 3)][(2, 6)]
    try
    {
        assert(hashTable.remove(-10));
        assert(hashTable.remove(4));
        assert(!hashTable.exists(-10) && !hashTable.exists(4));

        hashTable.add(2, 6);
        assert(hashTable.get(-5) == 4);
        assert(hashTable.get(10) == 3);
        assert(hashTable.get(2) == 6);
    }
    catch(const std::out_of_range &err)
    {
        rangeCheck = true;
    }
    catch(const std::invalid_argument &err)
    {
        validCheck = true;
    }
    assert(!rangeCheck && !validCheck);  

    std::cout << "PASSED!\n";
}

void runHtTests()
{
    std::cout << "running hash table tests...\n\n";

    runHiTest();
    runHtAddSearchRemoveTests();

    std::cout << "\nAll tests passed!\n";
}

int main()
{
    runHtTests();
    return 0;
}
