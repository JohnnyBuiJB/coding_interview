#include <iostream>
#include <string>
#include <cstdint>
#include <limits>
#include <vector>
#include "CppUTest/TestHarness.h"

using namespace std;

extern vector<int> twoSum(vector<int>& nums, int target);

TEST_GROUP(func) {
    void setup() {
    }

    void teardown() {
    }
};

TEST(func, TC001) {
    // Prepare data
    // vector<int> in (2,7,11);
    vector<int> in = {2,7,11,15};
    int target = 9;
    vector<int> exp_out(0,1);

    auto ret = twoSum(in, target);

    CHECK(exp_out == ret);
}

TEST(func, TC002) {
    // // Prepare data
    // string in1("rat");
    // string in2("car");

    // auto ret = isAnagram(in1, in2);

    // CHECK_EQUAL(false, ret);
}
