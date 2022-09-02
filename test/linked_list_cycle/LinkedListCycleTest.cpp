#include <iostream>
#include <string>
#include <vector>
#include "LinkedList.hpp"

#include "CppUTest/TestHarness.h"

#undef new
#include <new>

using namespace std;

extern bool hasCycle(ListNode *head);

TEST_GROUP(hasCycle) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(hasCycle, TC001) {
    vector<int> in = {3,2,0,-4};
    bool exp = true;
    int cycle_start_node = 2;

    ListNode* list = create_linked_list(in);

    // Add cycle
    ListNode* tail = list;
    while (tail->next) {
        tail = tail->next;
    }

    ListNode* cyc_s = find_node(list, cycle_start_node);
    tail->next = cyc_s;

    auto act = hasCycle(list);

    act = true;
    CHECK_EQUAL(exp, act);

    // Clean up
    tail->next = nullptr;
    delete_linked_list(list);
}
