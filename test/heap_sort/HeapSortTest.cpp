#include <iostream>

#include "CppUTest/TestHarness.h"
#include "HeapSort.hpp"
#include <vector>

#undef new
#include <new>

TEST_GROUP(HeapSort) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(HeapSort, TC001) {
    std::vector<int> v = {1,2,4,2,1,4,6,8};
    heapSort(v);

    

    CHECK_EQUAL(exp, act);
}
