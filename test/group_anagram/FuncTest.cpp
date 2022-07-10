#include <iostream>
#include <string>
#include <cstdint>
#include <limits>
#include <vector>
#include "CppUTest/TestHarness.h"

using namespace std;

extern vector<vector<string> > groupAnagrams(vector<string>& strs);

TEST_GROUP(func) {
    void setup() {
    }

    void teardown() {
    }
};

TEST(func, TC001) {
    // Prepare data
    vector<string> in({"eat","tea","tan","ate","nat","bat"});
    vector< vector<string> > exp_out{
        vector<string>{"bat"},
        vector<string>{"tan","nat"},
        vector<string>{"eat","tea","ate"}
        };

    auto ret = groupAnagrams(in);

    CHECK(exp_out == ret);
}

TEST(func, TC002) {
    vector<string> in({"ac","c"});
    vector< vector<string> > exp_out{
        vector<string>{"c"}, 
        vector<string>{"ac"}};

    auto ret = groupAnagrams(in);

    CHECK(exp_out == ret);
}
