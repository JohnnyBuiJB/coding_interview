#include <iostream>
#include <string>
#include <vector>

#include "CppUTest/TestHarness.h"
#include "LinkedListTestHelper.hpp"


#undef new
#include <new>

using namespace std;

extern ListNode* reverseKGroup(ListNode* head, int k);

TEST_GROUP(reverseKGroup) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(reverseKGroup, TC001) {
    vector<int> in = {1,2,3,4,5};
    vector<int> exp = {2,1,4,3,5};
    int k = 2;

    auto in_ll = create_linked_list(in);
    auto exp_ll = create_linked_list(exp);

    auto act_ll = reverseKGroup(in_ll, k);

    CHECK_EQUAL(true, equal_two_ll(act_ll, exp_ll));

    delete_linked_list(act_ll);
    delete_linked_list(exp_ll);
}
