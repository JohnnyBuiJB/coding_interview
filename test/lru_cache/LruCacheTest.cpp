#include <iostream>
#include <string>
#include <vector>

#include "CppUTest/TestHarness.h"
#include "LruCache.hpp"


#undef new
#include <new>

using namespace std;

TEST_GROUP(LRUCache) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(LRUCache, TC001) {
    LRUCache *obj = new LRUCache(2);
    obj->put(1, 1); // cache is {1=1}
    obj->put(2, 2); // cache is {1=1, 2=2}
    
    auto act = obj->get(1);    // return 1
    CHECK_EQUAL(1, act);

    obj->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    
    act = obj->get(2);    // not found
    CHECK_EQUAL(-1, act);

    obj->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    act = obj->get(1);    // not found
    CHECK_EQUAL(-1, act);

    act = obj->get(3);    // return 3
    CHECK_EQUAL(3, act);

    act = obj->get(4);    // return 4
    CHECK_EQUAL(4, act);

    delete obj;
}
