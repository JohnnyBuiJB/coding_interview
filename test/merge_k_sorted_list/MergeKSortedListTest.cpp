#include <vector>

#include "CppUTest/TestHarness.h"
#include "LinkedListTestHelper.hpp"

#undef new
#include <new>

using namespace std;

extern ListNode* mergeKLists(vector<ListNode*>& lists);

TEST_GROUP(sample) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(sample, TC001) {
    vector< vector<int> > in = {{1,4,5},{1,3,4},{2,6}};
    vector<int> exp = {1,1,2,3,4,4,5,6};
    vector<ListNode *> lists;

    auto exp_ll = create_linked_list(exp);

    for (auto i : in) {
        lists.push_back(create_linked_list(i));
    }
    
    auto act_ll = mergeKLists(lists);
    auto act = equal_two_ll(exp_ll, act_ll);

    CHECK_EQUAL(true, act);

    delete_linked_list(exp_ll);
    delete_linked_list(act_ll);
}

TEST(sample, TC002) {
    vector< vector<int> > in = {{},{-1,5,11},{},{6,10}};
    vector<int> exp = {-1,5,6,10,11};
    vector<ListNode *> lists;

    auto exp_ll = create_linked_list(exp);

    for (auto i : in) {
        lists.push_back(create_linked_list(i));
    }
    
    auto act_ll = mergeKLists(lists);
    auto act = equal_two_ll(exp_ll, act_ll);

    CHECK_EQUAL(true, act);

    delete_linked_list(exp_ll);
    delete_linked_list(act_ll);
}

TEST(sample, TC003) {
    vector< vector<int> > in = {};
    vector<int> exp = {};
    vector<ListNode *> lists;

    auto exp_ll = create_linked_list(exp);

    for (auto i : in) {
        lists.push_back(create_linked_list(i));
    }
    
    auto act_ll = mergeKLists(lists);
    auto act = equal_two_ll(exp_ll, act_ll);

    CHECK_EQUAL(true, act);

    delete_linked_list(exp_ll);
    delete_linked_list(act_ll);
}
