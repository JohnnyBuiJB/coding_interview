#include <iostream>
#include <string>
#include <cstdint>
#include <limits>
#include <vector>
#include "CppUTest/TestHarness.h"

using namespace std;

extern string minWindow(string s, string t);

TEST_GROUP(func) {
    void setup() {
    }

    void teardown() {
    }
};

TEST(func, TC001) {
    // Prepare data
    string s = "ADOBECODEBANC";
    string t = "BANC";
    string exp = "BANC";

    auto ret = minWindow(s, t);

    CHECK(exp == ret);
}

TEST(func, TC002) {
    // Prepare data
    string s = "ab";
    string t = "a";
    string exp = "a";

    auto ret = minWindow(s, t);

    CHECK(exp == ret);
}

TEST(func, TC003) {
    // Prepare data
    string s = "cabefgecdaecf";
    string t = "cae";
    string exp = "aec";

    auto ret = minWindow(s, t);

    CHECK(exp == ret);
}
