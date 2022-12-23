#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "CppUTest/TestHarness.h"
#include "CombinationSum.hpp"


#undef new
#include <new>

bool equalVector(vector<vector<int> > v1, vector<vector<int> > v2) {
    bool result = false;

    for (auto& item : v1) {
        result = false;
        for (size_t i = 0; i < v2.size(); i++) {
            if (v2[i] == item) {
                v2.erase(v2.begin() + i);
                result = true;
                continue;
            }
        }
    }

    if (v2.size() != 0) {
        result = false;
    }

    return result;
}

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