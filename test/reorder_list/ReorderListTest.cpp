#include <iostream>
#include <string>
#include <vector>

#include "CppUTest/TestHarness.h"

#include "LinkedList.hpp"

#undef new
#include <new>

using namespace std;

extern void reorderList(ListNode* head);

TEST_GROUP(reorderList) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(reorderList, TC001) {
    vector<int> in = {1,2,3,4};
    vector<int> exp = {1,4,2,3};

    ListNode* list = create_linked_list(in);

    reorderList(list);

    ListNode* p = list;
    for (auto const& v : exp) {
        CHECK_EQUAL(v, p->val);
        p = p->next;
    }

    // Clean up
    delete_linked_list(list);
}

TEST(reorderList, TC002) {
    vector<int> in = {1,2,3,4,5};
    vector<int> exp = {1,5,2,4,3};

    ListNode* list = create_linked_list(in);

    reorderList(list);

    ListNode* p = list;
    for (auto const& v : exp) {
        CHECK_EQUAL(v, p->val);
        p = p->next;
    }

    // Clean up
    delete_linked_list(list);
}

TEST(reorderList, TC003) {
    vector<int> in = {1};
    vector<int> exp = {1};

    ListNode* list = create_linked_list(in);

    reorderList(list);

    ListNode* p = list;
    for (auto const& v : exp) {
        CHECK_EQUAL(v, p->val);
        p = p->next;
    }

    // Clean up
    delete_linked_list(list);
}

TEST(reorderList, TC004) {
    vector<int> in = {0};
    vector<int> exp = {0};

    ListNode* list = create_linked_list(in);

    reorderList(list);

    ListNode* p = list;
    for (auto const& v : exp) {
        CHECK_EQUAL(v, p->val);
        p = p->next;
    }

    // Clean up
    delete_linked_list(list);
}
