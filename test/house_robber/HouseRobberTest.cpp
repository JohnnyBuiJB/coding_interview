#include <iostream>

#include "CppUTest/TestHarness.h"
#include "HouseRobber.hpp"

#undef new
#include <new>

TEST_GROUP(HouseRobber) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(HouseRobber, TC001) {
    auto solution = Solution();
    vector<int> in = {1,2,3,1};
    int exp = 4;

    auto act = solution.rob(in);

    CHECK_EQUAL(exp, act);
}

TEST(HouseRobber, TC002) {
    auto solution = Solution();
    vector<int> in = {2,7,9,3,1};
    int exp = 12;

    auto act = solution.rob(in);

    CHECK_EQUAL(exp, act);
}
