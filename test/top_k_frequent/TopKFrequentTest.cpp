#include <iostream>
#include <string>
#include <cstdint>
#include <limits>
#include <vector>
#include "CppUTest/TestHarness.h"

#include "TopKFrequent.hpp"

using namespace std;
using namespace solution;

// extern vector<int> topKFrequent(vector<int>& nums, int k);

TEST_GROUP(func) {
    void setup() {
    }

    void teardown() {
    }
};

TEST(func, TC001) {
    // Prepare data
    vector<int> in = {1,1,1,2,2,3};
    int k = 2;
    vector<int> exp_out = {1,2};

    auto ret = topKFrequent(in, k);

    CHECK(ret == exp_out);
}
