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

extern int search(vector<int>& nums, int target);

TEST_GROUP(sample) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(sample, TC001) {
    vector<int> in = {4,5,6,7,0,1,2};
    int target = 0;
    auto exp = 4;

    auto act = search(in, target);
    CHECK(act == exp);
}

TEST(sample, TC002) {
    vector<int> in = {4,5,6,7,0,1,2};
    int target = 3;
    auto exp = -1;

    auto act = search(in, target);
    CHECK(act == exp);
}

TEST(sample, TC003) {
    vector<int> in = {1};
    int target = 0;
    auto exp = -1;

    auto act = search(in, target);
    CHECK(act == exp);
}
