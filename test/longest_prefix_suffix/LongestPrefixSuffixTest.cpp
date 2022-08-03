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

extern int lps(string s);

TEST_GROUP(sample) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(sample, TC001) {
    string s = "abab";
    int exp = 2;

    auto act = lps(s);
    CHECK(act == exp);
}

TEST(sample, TC002) {
    string s = "ababaca";
    int exp = 1;

    auto act = lps(s);
    CHECK(act == exp);
}

TEST(sample, TC003) {
    string s = "aaaa";
    int exp = 3;

    auto act = lps(s);
    CHECK(act == exp);
}

TEST(sample, TC004) {
    string s = "acccbaaacccbaac";
    int exp = 2;

    auto act = lps(s);
    CHECK(act == exp);
}

