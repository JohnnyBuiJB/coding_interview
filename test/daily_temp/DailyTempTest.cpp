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

extern vector<int> dailyTemperatures(vector<int>& temperatures);

TEST_GROUP(sample) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(sample, TC001) {
    vector<int> in = {73,74,75,71,69,72,76,73};
    vector<int> exp = {1,1,4,2,1,1,0,0};
    
    auto act = dailyTemperatures(in);
    CHECK(act == exp);
}

TEST(sample, TC002) {
    vector<int> in = {30,40,50,60};
    vector<int> exp = {1,1,1,0};
    
    auto act = dailyTemperatures(in);
    CHECK(act == exp);
}

TEST(sample, TC003) {
    vector<int> in = {30,60,90};
    vector<int> exp = {1,1,0};
    
    auto act = dailyTemperatures(in);
    CHECK(act == exp);
}
