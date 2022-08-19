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

extern int minEatingSpeed(vector<int>& piles, int h);

TEST_GROUP(KokoEatingBanana) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(KokoEatingBanana, TC001) {
    vector<int> piles = {3,6,7,11};
    int h = 8;
    auto exp = 4;

    auto act = minEatingSpeed(piles, h);
    CHECK(act == exp);
}

TEST(KokoEatingBanana, TC002) {
    vector<int> piles = {30,11,23,4,20};
    int h = 5;
    auto exp = 30;

    auto act = minEatingSpeed(piles, h);
    CHECK(act == exp);
}

TEST(KokoEatingBanana, TC003) {
    vector<int> piles = {30,11,23,4,20};
    int h = 6;
    auto exp = 23;

    auto act = minEatingSpeed(piles, h);
    CHECK(act == exp);
}

TEST(KokoEatingBanana, TC004) {
    vector<int> piles = {312884470};
    int h = 312884469;
    auto exp = 2;

    auto act = minEatingSpeed(piles, h);
    CHECK(act == exp);
}
