#include <iostream>
#include <string>
#include <cstdint>
#include <limits>
#include <vector>
#include "CppUTest/TestHarness.h"

extern bool isPalindromePermutation(std::string s);

TEST_GROUP(func) {
    void setup() {
    }

    void teardown() {
    }
};

TEST(func, TC001) {
    // Prepare data
    std::string s("abcbcbcbc");

    auto ret = isPalindromePermutation(s);

    CHECK_EQUAL(true, ret);
}

TEST(func, TC002) {
    // Prepare data
    std::string s("a b c c c c b a");

    auto ret = isPalindromePermutation(s);

    CHECK_EQUAL(true, ret);
}

TEST(func, TC003) {
    // Prepare data
    std::string s("AHA z x c xz");

    auto ret = isPalindromePermutation(s);

    CHECK_EQUAL(true, ret);
}
