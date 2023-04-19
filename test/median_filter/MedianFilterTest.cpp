#include <iostream>

#include "CppUTest/TestHarness.h"
#include "sample.hpp"

#undef new
#include <new>

TEST_GROUP(sample) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(sample, TC001) {
    auto solution = Solution();

    int exp = 1;

    auto act = solution.sampleCode();

    CHECK_EQUAL(exp, act);
}
