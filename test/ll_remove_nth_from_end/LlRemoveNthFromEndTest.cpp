#include "LinkedList.hpp"

#include "CppUTest/TestHarness.h"


#undef new
#include <new>

using namespace std;

extern ListNode* removeNthFromEnd(ListNode* head, int n);

TEST_GROUP(removeNthFromEnd) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(removeNthFromEnd, TC001) {
    vector<int> in = {1,2,3,4,5};
    vector<int> exp = {1,2,3,5};
    int n = 2;

    auto head = create_linked_list(in);

    auto act = removeNthFromEnd(head, n);

    for (auto const& v : exp) {
        CHECK_EQUAL(v, act->val);
        act = act->next;
    }

    delete_linked_list(head);
}
