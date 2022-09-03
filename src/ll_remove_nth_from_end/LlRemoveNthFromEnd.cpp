#include "LinkedList.hpp"

using namespace std;

/**
 * \Trick   Infer the position by the length of the list and traverse to it in 
 *          linear time.
 * \Time    O(n)
 * \Space   O(1)
 * \Ref     Bui V.
 */
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* cur = head;
    
    // Count the len
    int len = 0;

    while (cur) {
        len++;
        cur = cur->next;
    }

    // Traverse to the node
    int i = len - n;
    cur = head;
    ListNode* prev = nullptr;

    while (i) {
        prev = cur;
        cur = cur->next;
        i--;
    }

    if (prev) {
        prev->next = cur->next;
        delete cur; // Assume that we are supposed to free the memory of the node
    } 
    // Delete the head
    else {
        head = head->next;
    }
    
    return head;
}
