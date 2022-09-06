#include "LinkedListTestHelper.hpp"

bool equal_two_ll(ListNode* l1, ListNode* l2) {
    while (l1 && l2) {
        if (l1->val != l2->val) {
            return false;
        }

        l1 = l1->next;
        l2 = l2->next;
    }

    // Different length
    if (l1 || l2) {
        return false;
    }

    return true;
}
