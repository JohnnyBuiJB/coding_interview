#include <iostream>
#include <string>
#include <cstdint>
#include <limits>
#include <vector>
#include "CppUTest/TestHarness.h"

#include "ReverseArray.hpp"

TEST_GROUP(func) {
    void setup() {
    }

    void teardown() {
    }
};

TEST(func, TC001) {
    // Prepare data
    std::vector<int> in = {1,2,3};
    std::vector<int> exp_out = {3,2,1};

    reverse_array(in);

    CHECK(in == exp_out);
}

TEST(func, TC002) {
    // Prepare data
    std::vector<int> in = {4, 5, 1, 2};
    std::vector<int> exp_out = {2, 1, 5, 4};

    reverse_array(in);

    CHECK(in == exp_out);
}
