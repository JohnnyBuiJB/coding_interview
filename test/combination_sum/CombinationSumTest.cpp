#include <iostream>
#include <string>
#include <vector>

#include "VectorTestHelper.hpp"
#include "CppUTest/TestHarness.h"
#include "CombinationSum.hpp"


#undef new
#include <new>

TEST_GROUP(CombinationSum) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(CombinationSum, TC001) {
    auto sol = Solution();
    vector<int> in = {2,3,6,7};
    int target = 7;
    
    vector<vector<int> > exp = {
        {2,2,3},
        {7}
    };

    auto act = sol.combinationSum(in, target);
    auto result = equalVector(act, exp);

    CHECK(result == true);
}

TEST(CombinationSum, TC002) {
    auto sol = Solution();
    vector<int> in = {8,7,4,3};
    int target = 11;
    
    vector<vector<int> > exp = {
        {8,3},
        {7,4},
        {4,4,3}
    };

    auto act = sol.combinationSum(in, target);
    auto result = equalVector(act, exp);

    CHECK(result == true);
}