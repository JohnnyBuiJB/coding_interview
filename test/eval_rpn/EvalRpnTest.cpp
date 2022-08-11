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

extern int evalRPN(vector<string>& tokens);

TEST_GROUP(sample) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(sample, TC001) {
    vector<string> in = {"2","1","+","3","*"};
    auto exp = 9;

    auto act = evalRPN(in);
    CHECK(act == exp);
}

TEST(sample, TC002) {
    vector<string> in = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    auto exp = 22;

    auto act = evalRPN(in);
    CHECK(act == exp);
}
