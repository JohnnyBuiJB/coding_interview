#include <iostream>
#include <string>
#include <cstdint>
#include <limits>
#include <vector>
#include "CppUTest/TestHarness.h"

using namespace std;

extern bool isAnagram(string s, string t);

TEST_GROUP(func) {
    void setup() {
    }

    void teardown() {
    }
};

TEST(func, TC001) {
    // Prepare data
    string in1("anagram");
    string in2("nagaram");

    auto ret = isAnagram(in1, in2);

    CHECK_EQUAL(true, ret);
}

TEST(func, TC002) {
    // Prepare data
    string in1("rat");
    string in2("car");

    auto ret = isAnagram(in1, in2);

    CHECK_EQUAL(false, ret);
}
