#include <iostream>

#include "CppUTest/TestHarness.h"
#include "HouseRobber2.hpp"

#undef new
#include <new>

TEST_GROUP(HouseRobber2) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(HouseRobber2, TC001) {
    auto solution = Solution();
    vector<int> in = {2,3,2};
    int exp = 3;

    auto act = solution.rob(in);

    CHECK_EQUAL(exp, act);
}

TEST(HouseRobber2, TC002) {
    auto solution = Solution();
    vector<int> in = {1,2,3};
    int exp = 3;

    auto act = solution.rob(in);

    CHECK_EQUAL(exp, act);
}

TEST(HouseRobber2, TC003) {
    auto solution = Solution();
    vector<int> in = {0};
    int exp = 0;

    auto act = solution.rob(in);

    CHECK_EQUAL(exp, act);
}

TEST(HouseRobber2, TC004) {
    auto solution = Solution();
    vector<int> in = {1};
    int exp = 1;

    auto act = solution.rob(in);

    CHECK_EQUAL(exp, act);
}

TEST(HouseRobber2, TC005) {
    auto solution = Solution();
    vector<int> in = {200,3,140,20,10};
    int exp = 340;

    auto act = solution.rob(in);

    CHECK_EQUAL(exp, act);
}

TEST(HouseRobber2, TC006) {
    auto solution = Solution();
    vector<int> in = {8,2,8,9,2};
    int exp = 17;

    auto act = solution.rob(in);

    CHECK_EQUAL(exp, act);
}
