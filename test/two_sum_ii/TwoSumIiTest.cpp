#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "CppUTest/TestHarness.h"


#undef new
#include <new>

using namespace std;

extern vector<int> twoSumII(vector<int>& numbers, int target);

TEST_GROUP(sample) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(sample, TC001) {
    vector<int> in = {2,7,11,15};
    vector<int> exp = {1,2};
    int target = 9;

    auto act = twoSumII(in, target);
    CHECK(act == exp);
}

TEST(sample, TC002) {
    vector<int> in = {2,3,4};
    vector<int> exp = {1,3};
    int target = 6;

    auto act = twoSumII(in, target);
    CHECK(act == exp);
}

TEST(sample, TC003) {
    vector<int> in = {-1,0};
    vector<int> exp = {1,2};
    int target = -1;

    auto act = twoSumII(in, target);
    CHECK(act == exp);
}
