#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "CppUTest/TestHarness.h"
#include "LinkedList.hpp"

#undef new
#include <new>

using namespace std;

class Node;
extern Node* copyRandomList(Node* head);

TEST_GROUP(copyRandomList) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(copyRandomList, TC001) {
    vector<int> in = {1,2};

    Node* head = create_random_linked_list(in);

    Node* copy_head = copyRandomList(head);
    Node* copy = copy_head;

    for (auto const& v : in) {
        CHECK_EQUAL(v, copy->val);
        copy = copy->next;
    }

    delete_random_linked_list(head);
    delete_random_linked_list(copy_head);
}
