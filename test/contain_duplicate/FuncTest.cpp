#include <iostream>
#include <string>
#include <cstdint>
#include <limits>
#include <vector>
#include "CppUTest/TestHarness.h"

using namespace std;

extern bool containDuplicate(std::vector<int> nums);

TEST_GROUP(func) {
    void setup() {
    }

    void teardown() {
    }
};

TEST(func, TC001) {
    // Prepare data
    vector<int> in = {1,2,3,1};

    auto ret = containDuplicate(in);

    CHECK_EQUAL(true, ret);
}

TEST(func, TC002) {
    // Prepare data
    vector<int> in = {1,2,3,4};

    auto ret = containDuplicate(in);

    CHECK_EQUAL(false, ret);
}

TEST(func, TC003) {
    // Prepare data
    vector<int> in = {1,1,1,3,3,4,3,2,4,2};

    auto ret = containDuplicate(in);

    CHECK_EQUAL(true, ret);
}
