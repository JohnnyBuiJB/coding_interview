#include <iostream>
#include <unistd.h>
#include <string>
#include <math.h>
#include <dirent.h>
#include <vector>
#include "CppUTest/TestHarness.h"

#include "sample.hpp"

#undef new
#include <new>

TEST_GROUP(sample) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

// 1. Input domain
TEST(sample, test_case_1) {
    sample_code();
    CHECK(NULL == NULL);
}
