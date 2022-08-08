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

extern int maxArea(vector<int>& height);

TEST_GROUP(sample) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(sample, TC001) {
    vector<int> in = {1,8,6,2,5,4,8,3,7};
    auto exp = 49;

    auto act = maxArea(in);
    CHECK(act == exp);
}

TEST(sample, TC002) {
    vector<int> in = {1,1};
    auto exp = 1;

    auto act = maxArea(in);
    CHECK(act == exp);
}
