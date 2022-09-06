#include <vector>

#include "CppUTest/TestHarness.h"
#include "LinkedListTestHelper.hpp"


#undef new
#include <new>

using namespace std;

extern ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

TEST_GROUP(addTwoNumbers) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(addTwoNumbers, TC001) {
    vector<int> in1 = {2,4,3};
    vector<int> in2 = {5,6,4};
    vector<int> exp = {7,0,8};

    auto in1_head = create_linked_list(in1);
    auto in2_head = create_linked_list(in2);
    auto exp_head = create_linked_list(exp);

    auto act_head = addTwoNumbers(in1_head, in2_head);

    auto act = equal_two_ll(exp_head, act_head);
    
    CHECK_EQUAL(true, act);

    delete_linked_list(in1_head);
    delete_linked_list(in2_head);
    delete_linked_list(exp_head);
    delete_linked_list(act_head);
}

TEST(addTwoNumbers, TC002) {
    vector<int> in1 = {9,9,9,9};
    vector<int> in2 = {9,9,9,9,9,9,9};
    vector<int> exp = {8,9,9,9,0,0,0,1};

    auto in1_head = create_linked_list(in1);
    auto in2_head = create_linked_list(in2);
    auto exp_head = create_linked_list(exp);

    auto act_head = addTwoNumbers(in1_head, in2_head);

    auto act = equal_two_ll(exp_head, act_head);
    
    CHECK_EQUAL(true, act);

    delete_linked_list(in1_head);
    delete_linked_list(in2_head);
    delete_linked_list(exp_head);
    delete_linked_list(act_head);
}
