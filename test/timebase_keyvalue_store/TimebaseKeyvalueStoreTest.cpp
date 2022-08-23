#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "TimebaseKeyvalueStore.hpp"

#include "CppUTest/TestHarness.h"


#undef new
#include <new>

using namespace std;

TEST_GROUP(sample) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(sample, TC001) {
    TimeMap* p_obj = new TimeMap();

    p_obj->set("love", "high", 10);
    p_obj->set("love", "low", 20);
    
    auto act = p_obj->get("love", 5);
    CHECK(act == "");

    act = p_obj->get("love", 10);
    CHECK(act == "high");

    act = p_obj->get("love", 15);
    CHECK(act == "high");

    act = p_obj->get("love", 20);
    CHECK(act == "low");

    act = p_obj->get("love", 25);
    CHECK(act == "low");

    delete p_obj;
}

// exp [null,null,null,"","high","high","low","low"]
// out [null,null,null,"low","low","low","low","low"]
