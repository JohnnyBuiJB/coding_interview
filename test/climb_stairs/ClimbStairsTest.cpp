#include <iostream>

#include "CppUTest/TestHarness.h"
#include "ClimbStairs.hpp"

#undef new
#include <new>

TEST_GROUP(ClimbStairs) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(ClimbStairs, TC001) {
    auto solution = Solution();
    int n = 0;
    int exp = 0;

    auto act = solution.climbStairs(n);

    CHECK_EQUAL(exp, act);
}

TEST(ClimbStairs, TC002) {
    auto solution = Solution();
    int n = 1;
    int exp = 1;

    auto act = solution.climbStairs(n);

    CHECK_EQUAL(exp, act);
}

TEST(ClimbStairs, TC003) {
    auto solution = Solution();
    int n = 5;
    int exp = 8;

    auto act = solution.climbStairs(n);

    CHECK_EQUAL(exp, act);
}
