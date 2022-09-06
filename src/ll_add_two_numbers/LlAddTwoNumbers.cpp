#include "LinkedList.hpp"

using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* sum_head = nullptr;
    ListNode* prev = nullptr;
    bool carry = false;
    
    // Terminate when both lists reach the end
    while (l1 || l2) {
        int val1 = 0;
        int val2 = 0;
        int sum = 0;

        if (l1) {
            val1 = l1->val;
            l1 = l1->next;
        }

        if (l2) {
            val2 = l2->val;
            l2 = l2->next;
        }

        sum = carry ? val1 + val2 + 1 : val1 + val2;
        carry = sum > 9;

        ListNode* new_node = new ListNode(sum % 10);

        if (!sum_head) {
            sum_head = new_node;
        }

        if (prev) {
            prev->next = new_node;
        }

        prev = new_node;
    }

    if (carry) {
        ListNode* new_node = new ListNode(1);
        
        // prev is always well defined when carry is true
        prev->next = new_node;
    }

    return sum_head;
}