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

extern bool isValid(string s);

TEST_GROUP(sample) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(sample, TC001) {
    string in = "()";
    auto exp = true;

    auto act = isValid(in);
    CHECK(act == exp);
}

TEST(sample, TC002) {
    string in = "(";
    auto exp = false;

    auto act = isValid(in);
    CHECK(act == exp);
}
