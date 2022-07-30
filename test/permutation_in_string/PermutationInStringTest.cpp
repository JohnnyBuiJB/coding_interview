#include <iostream>
#include <string>
#include <cstdint>
#include <limits>
#include <vector>
#include "CppUTest/TestHarness.h"

using namespace std;

extern bool checkInclusion(string s1, string s2);

TEST_GROUP(func) {
    void setup() {
    }

    void teardown() {
    }
};

TEST(func, TC001) {
    // Prepare data
    string s1 = "ab";
    string s2 = "eidbaooo";
    int exp = true;

    auto ret = checkInclusion(s1, s2);

    CHECK_EQUAL(exp, ret);
}

TEST(func, TC002) {
    // Prepare data
    string s1 = "dinitrophenylhydrazine";
    string s2 = "dimethylhydrazine";
    int exp = false;

    auto ret = checkInclusion(s1, s2);

    CHECK_EQUAL(exp, ret);
}

TEST(func, TC003) {
    // Prepare data
    string s1 = "abcdxabcde";
    string s2 = "abcdeabcdx";
    int exp = true;

    auto ret = checkInclusion(s1, s2);

    CHECK_EQUAL(exp, ret);
}
