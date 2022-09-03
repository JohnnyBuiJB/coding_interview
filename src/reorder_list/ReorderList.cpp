#include <stack>
#include "LinkedList.hpp"

using namespace std;

#define     OPTIMAL     1
#define     USE_STACK   1

extern ListNode* reverseList(ListNode* head);

/**
 * \Trick   Reverse the second half
 * 
 *          The list will be modified eventually, so we are free to modify it 
 *          in any way before reordering it. In particular, the second part of 
 *          the list can be reversed so that we can iterate backward from the 
 *          tail in constant time.
 * \Time    O(n)
 * \Space   O(1)
 * \Ref     Neetcode
 */

/**
 * \Trick   Using stack to store the second half so that we can iterate backward 
 *          from the tail in constant time
 * \Time    O(n)
 * \Space   O(n)
 * \Ref     Bui V.
 */
void reorderList(ListNode* head) {
    // Empty list
    if (!head) {
        // Do nothing
        return;
    }

    // List contain one node
    if (!head->next) {
        // Do nothing
        return;
    }

    ListNode* p_head = head;
    
#if OPTIMAL == 1
    // Search for the middle node using two pointers (slow and fast)
    ListNode* slow = p_head;
    ListNode* fast = p_head;
    ListNode* mid = nullptr;    // Head of the second part

    while (1) {
        // even len
        if (!fast) {
            mid = slow;
            break;
        }
        
        fast = fast->next;

        // odd len
        if (!fast) {
            mid = slow->next;
            break;
        } 
        
        fast = fast->next;
        slow = slow->next;  // slow is guaranteed not to be null
    }

    // Reverse the second part
    ListNode* tail = reverseList(mid);
    ListNode* next;

    // Reorder
    while (p_head) {
        next = p_head->next;
        p_head->next = tail;

        // Update head
        p_head = next;

        if (tail) {
            next = tail->next;
            tail->next = p_head;
            tail = next;
        } else {
            break;
        }
    }
    
#else
#if USE_STACK == 1
    // Build a stack of nodes' addresses
    stack<ListNode*> node_stack;
    ListNode* p = p_head;

    while (p) {
        node_stack.push(p);
        p = p->next;
    }

    // Reorder until 2 pointers meet
    ListNode* tail = node_stack.top();  // The stack is guaranteed to be non-empty
    node_stack.pop();
    ListNode* next = nullptr;

    while (p_head != tail) {
        next = p_head->next;
        p_head->next = tail;
        
        // Update head
        p_head = next;

        if (tail != p_head) {
            tail->next = p_head;
            
            // Update tail
            tail = node_stack.top();
            node_stack.pop();
        }
    }

    p_head->next = nullptr;
#endif
#endif
}

