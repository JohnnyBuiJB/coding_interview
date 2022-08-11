#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "MinStack.hpp"

#include "CppUTest/TestHarness.h"


#undef new
#include <new>

using namespace std;

extern int sample_code(int a);

TEST_GROUP(sample) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(sample, TC001) {
    MinStack *p_ms = new MinStack();
    p_ms->push(-2);
    p_ms->push(0);
    p_ms->push(-3);
    
    int ret = p_ms->getMin();
    CHECK(ret == -3);

    p_ms->pop();
    
    ret = p_ms->top();
    CHECK(ret == 0);

    ret = p_ms->getMin();
    CHECK(ret == -2);

    delete p_ms;
}
