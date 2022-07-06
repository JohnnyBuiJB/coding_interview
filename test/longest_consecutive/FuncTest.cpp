#include <iostream>
#include <string>
#include <cstdint>
#include <limits>
#include <vector>
#include "CppUTest/TestHarness.h"

using namespace std;

extern int longestConsecutive(vector<int>& nums);

TEST_GROUP(func) {
    void setup() {
    }

    void teardown() {
    }
};

TEST(func, TC001) {
    // Prepare data
    vector<int> in({100,4,200,1,3,2});

    auto ret = longestConsecutive(in);

    CHECK_EQUAL(4, ret);
}

TEST(func, TC002) {
    // Prepare data
}

TEST(func, TC003) {
    // Prepare data
}
