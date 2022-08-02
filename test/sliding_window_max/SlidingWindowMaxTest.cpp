#include <iostream>
#include <string>
#include <cstdint>
#include <limits>
#include <vector>
#include "CppUTest/TestHarness.h"

using namespace std;

extern vector<int> maxSlidingWindow(vector<int>& nums, int k);

TEST_GROUP(func) {
    void setup() {
    }

    void teardown() {
    }
};

TEST(func, TC001) {
    // Prepare data
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> exp = {3,3,5,5,6,7};

    auto ret = maxSlidingWindow(nums, k);

    CHECK(exp == ret);
}

TEST(func, TC002) {
    // Prepare data
    vector<int> nums = {1};
    vector<int> exp = {1};
    int k = 1;

    auto ret = maxSlidingWindow(nums, k);

    CHECK(exp == ret);
}
