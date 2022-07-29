#include <iostream>
#include <string>
#include <cstdint>
#include <limits>
#include <vector>
#include "CppUTest/TestHarness.h"

using namespace std;

extern int maxStockProfit(vector<int>& prices);

TEST_GROUP(func) {
    void setup() {
    }

    void teardown() {
    }
};

TEST(func, TC001) {
    // Prepare data
    vector<int> in = {7,1,5,3,6,4};
    int exp = 5;

    auto ret = maxStockProfit(in);

    CHECK_EQUAL(exp, ret);
}

TEST(func, TC002) {
    // Prepare data
    vector<int> in = {7,6,4,3,1};
    int exp = 0;

    auto ret = maxStockProfit(in);

    CHECK_EQUAL(exp, ret);
}
