#include <iostream>
#include <string>
#include <cstdint>
#include <limits>
#include <vector>
#include "CppUTest/TestHarness.h"

using namespace std;

extern int minSwap(int arr[], int n, int k);

TEST_GROUP(func) {
    void setup() {
    }

    void teardown() {
    }
};

TEST(func, TC001) {
    // Prepare data
    int in[] = {2,1,5,6,3};
    int k = 3;

    auto ret = minSwap(in, sizeof(in) / sizeof(int), k);

    CHECK_EQUAL(1, ret);
}

TEST(func, TC002) {
    // Prepare data
    int in[] = {2, 7, 9, 5, 8, 7, 4};
    int k = 6;

    auto ret = minSwap(in, sizeof(in) / sizeof(int), k);

    CHECK_EQUAL(2, ret);
}
