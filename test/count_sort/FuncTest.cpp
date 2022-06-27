#include <iostream>
#include <string>
#include <cstdint>
#include <limits>
#include <vector>
#include "CppUTest/TestHarness.h"

extern void count_sort(int a[], int n);

TEST_GROUP(func) {
    void setup() {
    }

    void teardown() {
    }
};

TEST(func, TC001) {
    // Prepare data
    int in[] = {0,1,2,1,2,1,0};
    int exp_out[] = {0,0,1,1,1,2,2};

    count_sort(in, sizeof(in) / sizeof(int));

    MEMCMP_EQUAL(in, exp_out, sizeof(in));
}
