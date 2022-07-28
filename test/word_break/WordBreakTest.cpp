#include <iostream>
#include <string>
#include <cstdint>
#include <limits>
#include <vector>
#include "CppUTest/TestHarness.h"

using namespace std;

extern int wordBreak(string A, vector<string> &B);

TEST_GROUP(func) {
    void setup() {
    }

    void teardown() {
    }
};

TEST(func, TC001) {
    // Prepare data
    // string in = "i like sam sung samsung mobile ice cream icecream man go mango";
    string in = "ilike";
    vector<string> in2 = {"i", "like", "sam",
        "sung", "samsung", "mobile",
        "ice","cream", "icecream",
        "man", "go", "mango"};

    auto ret = wordBreak(in, in2);

    CHECK_EQUAL(1, ret);
}
