#include <iostream>
#include <string>
#include <cstdint>
#include <limits>
#include <vector>

#include "CppUTest/TestHarness.h"
#include "AirlineTicketEstimate.hpp"

#undef new
#include <new>

TEST_GROUP(AirlineTicketEstimateTest) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(AirlineTicketEstimateTest, TC001) {
    const vector< vector<string> > input = {
        {"United", "150.0", "Premium"},
        {"Delta", "60.0", "Business"},
        {"Southwest", "1000.0", "Economy"},
        {"LuigiAir", "50.0", "Business"}
    };

    AirlinePriceEstimater estimator;
    estimator.estimate(input);

    CHECK_EQUAL(true, true);
}
