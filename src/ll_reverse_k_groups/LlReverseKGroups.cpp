#include "LinkedList.hpp"

extern ListNode* reverseList(ListNode* head);

ListNode* reverseKGroup(ListNode* head, int k) {
    // Sanity check (k is guaranteed to be 1 <= k <= n)
    if (!head) {
        return nullptr;
    }
    
    ListNode* new_list_head = nullptr;
    ListNode* tail = head;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;

    while (head) {
        int len = 1;
        // Break down the list into k-lists
        while (len < k) {
            if (tail->next) {
                tail = tail->next;
                len++;
            } else {
                break;
            }
        }

        // Save state
        next = tail->next;  // tail is guaranteed not to be nullptr

        // K-lists
        if (len == k) {
            // Disconnect
            tail->next = nullptr;

            reverseList(head);

            // Reconnect
            if (prev) {
                prev->next = tail;  // tail becomes head after the reverse
            }
        } 
        // The left-out
        else {
            // Reconnect
            if (prev) {
                prev->next = head;
            }
        }

        // Connect the head
        if (!new_list_head) {
            // The first k-list is always reversed because 1 <= k <= n
            new_list_head = tail;   // tail becomes head after the reverse
        }

        // Update states for next iteration
        prev = head;    // head becomes tail after the reverse
        tail = head = next;
    }

    return new_list_head;
}