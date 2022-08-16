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

extern int largestRectangleArea(vector<int>& heights);

TEST_GROUP(sample) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(sample, TC001) {
    vector<int> h = {2,1,5,6,2,3};
    auto exp = 10;

    auto act = largestRectangleArea(h);
    CHECK(act == exp);
}

TEST(sample, TC002) {
    vector<int> h = {2,4};
    auto exp = 4;

    auto act = largestRectangleArea(h);
    CHECK(act == exp);
}

TEST(sample, TC003) {
    vector<int> h = {2,1,2};
    auto exp = 3;

    auto act = largestRectangleArea(h);
    CHECK(act == exp);
}
