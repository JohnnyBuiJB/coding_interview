#include <iostream>

#include "CppUTest/TestHarness.h"
#include "Fibonacci.hpp"

#undef new
#include <new>

TEST_GROUP(fibonacci) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(fibonacci, TC001) {
    auto solution = Solution();

    int exp = 21;

    auto act = solution.fibonacci(8);
    cout << solution.getNumCalls() << endl;

    CHECK_EQUAL(exp, act);
}
