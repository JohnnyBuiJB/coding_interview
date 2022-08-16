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

extern int carFleet(int target, vector<int>& position, vector<int>& speed);

TEST_GROUP(sample) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(sample, TC001) {
    vector<int> pos = {10,8,0,5,3};
    vector<int> speed = {2,4,1,1,3};
    int target = 12;
    int exp = 3;

    auto act = carFleet(target, pos, speed);
    CHECK(act == exp);
}
