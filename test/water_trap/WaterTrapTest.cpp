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

extern int trap(vector<int>& height);

TEST_GROUP(sample) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(sample, TC001) {
    vector<int> in = {0,1,0,2,1,0,1,3,2,1,2,1};
    int exp = 6;

    int act = trap(in);
    CHECK(act == exp);
}

TEST(sample, TC002) {
    vector<int> in = {9,2,9,3,2,2,1,4,8};
    int exp = 35;

    int act = trap(in);
    CHECK(act == exp);
}
