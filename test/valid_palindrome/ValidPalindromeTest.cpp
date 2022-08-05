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

extern bool isPalindrome(string s);

TEST_GROUP(sample) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(sample, TC001) {
    string in = "A man, a plan, a canal: Panama";
    bool exp = true;
    
    bool act = isPalindrome(in);
    CHECK(act == exp);
}

TEST(sample, TC002) {
    string in = "0P";
    bool exp = false;
    
    bool act = isPalindrome(in);
    CHECK(act == exp);
}
