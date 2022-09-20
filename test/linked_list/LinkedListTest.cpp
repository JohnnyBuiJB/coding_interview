#include <iostream>
#include <string>
#include <vector>
#include "LinkedList.hpp"

#include "CppUTest/TestHarness.h"

#undef new
#include <new>

using namespace std;

bool create_linked_list_test(ListNode* head, vector<int> values) {
    // Empty list
    if (!head && values.empty()) {
        return true;
    } else if (head && !values.empty()) {
        for (auto const& v : values) {
            // List is shorter
            if (!head) {
                return false;
            }

            // Incorrect value
            if (v != head->val) {
                return false;
            }
            head = head->next;
        }

        // Vector is shorter
        if (head) {
            return false;
        }
    }

    return true;
}

TEST_GROUP(create_linked_list) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(create_linked_list, TC001) {
    vector<int> in = {3,2,0,-4};

    ListNode* list = create_linked_list(in);

    auto act = create_linked_list_test(list, in);
    
    CHECK_EQUAL(true, act);
    
    delete_linked_list(list);
}

TEST(create_linked_list, TC002) {
    vector<int> in = {};

    ListNode* list = create_linked_list(in);

    auto act = create_linked_list_test(list, in);
    
    CHECK_EQUAL(true, act);
    
    delete_linked_list(list);
}

TEST_GROUP(find_node) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(find_node, TC001) {
    vector<int> in = {3,2,0,-4};
    int search_val = 0;

    ListNode* list = create_linked_list(in);

    ListNode* node = find_node(list, search_val);

    CHECK_EQUAL(search_val, node->val);

    delete_linked_list(list);
}

TEST(find_node, TC002) {
    vector<int> in = {3,2,0,-4};
    int search_val = 5;

    ListNode* list = create_linked_list(in);

    ListNode* node = find_node(list, search_val);

    CHECK_EQUAL(NULL, node);

    delete_linked_list(list);
}

TEST(find_node, TC003) {
    vector<int> in = {};
    int search_val = 5;

    ListNode* list = create_linked_list(in);

    ListNode* node = find_node(list, search_val);

    CHECK_EQUAL(NULL, node);

    delete_linked_list(list);
}

TEST_GROUP(doubly_linked_list) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(doubly_linked_list, TC001) {
    vector<int> in = {1,2,3,4};

    DoublyLinkedList* list = create_doubly_linked_list(in);

    for (auto& v : in) {
        auto node = list->front();

        CHECK_EQUAL(v, node->value);
        list->pop_front();
    }

    delete list;
}

TEST(doubly_linked_list, TC002) {
    vector<int> in = {1,2,3,4};
    vector<int> exp = {1,2,10,3,4};

    DoublyLinkedList* list = create_doubly_linked_list(in);

    auto node_two = list->find_node(2);
    DoublyLinkedNode* new_node = new DoublyLinkedNode(10);
    list->insert_after(new_node, node_two);

    DoublyLinkedNode* cur = list->front();

    for (auto &v : exp) {
        CHECK_EQUAL(v, cur->value);
        cur = cur->next;
    }

    delete list;
}
