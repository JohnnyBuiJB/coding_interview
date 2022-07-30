#include <iostream>
#include <string>
#include <cstdint>
#include <limits>
#include <vector>
#include "CppUTest/TestHarness.h"

using namespace std;

extern int lengthOfLongestSubstring(string s);

TEST_GROUP(func) {
    void setup() {
    }

    void teardown() {
    }
};

TEST(func, TC001) {
    // Prepare data
    string s = "abcabcbb";
    int exp = 3;

    auto ret = lengthOfLongestSubstring(s);

    CHECK_EQUAL(exp, ret);
}

