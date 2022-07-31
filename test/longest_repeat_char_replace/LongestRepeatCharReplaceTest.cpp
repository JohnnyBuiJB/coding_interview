#include <iostream>
#include <string>
#include <cstdint>
#include <limits>
#include <vector>
#include "CppUTest/TestHarness.h"

using namespace std;

extern int characterReplacement(string s, int k);

TEST_GROUP(func) {
    void setup() {
    }

    void teardown() {
    }
};

TEST(func, TC001) {
    // Prepare data
    string s = "ABAB";
    int k = 2;
    int exp = 4;

    auto ret = characterReplacement(s, k);

    CHECK_EQUAL(exp, ret);
}

TEST(func, TC002) {
    // Prepare data
    string s = "AABABBA";
    int k = 1;
    int exp = 4;

    auto ret = characterReplacement(s, k);

    CHECK_EQUAL(exp, ret);
}

