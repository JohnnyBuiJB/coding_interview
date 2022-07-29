#include <iostream>
#include <string>
#include <cstdint>
#include <limits>
#include <vector>
#include "CppUTest/TestHarness.h"

using namespace std;

extern int maxSubArr(vector<int>& arr, int b, int e);

TEST_GROUP(func) {
    void setup() {
    }

    void teardown() {
    }
};

TEST(func, TC001) {
    // Prepare data
    vector<int> in = {-6,4,-2,3,-2};
    int exp = 5;

    auto ret = maxSubArr(in, 0, in.size() - 1);

    CHECK_EQUAL(exp, ret);
}

TEST(func, TC002) {
    // Prepare data
    vector<int> in = {-1,1,-1,-1,0,1};
    int exp = 1;

    auto ret = maxSubArr(in, 0, in.size() - 1);

    CHECK_EQUAL(exp, ret);
}
