#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "CppUTest/TestHarness.h"
#include "LinkedList.hpp"

extern ListNode* reverseList(ListNode* head);

#undef new
#include <new>

using namespace std;

TEST_GROUP(sample) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(sample, TC001) {
    ListNode* p_head = new ListNode(1);
    ListNode* p_cur = p_head;

    int i = 2;
    while (i <= 4) {
        ListNode* p_node = new ListNode(i);
        p_cur->next = p_node;
        p_cur = p_node;

        i++;
    }

    ListNode* p_tail = reverseList(p_head);
    CHECK(p_tail != nullptr);

    // Clean up
    delete_linked_list(p_tail);
}

TEST(sample, TC002) {
    ListNode* p_head = nullptr;
    ListNode* p_tail = reverseList(p_head);
    CHECK(p_tail == nullptr);

    // Clean up
    delete_linked_list(p_tail);
}