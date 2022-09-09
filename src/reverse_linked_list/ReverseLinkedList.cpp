#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "LinkedList.hpp"

using namespace std;

ListNode* reverseList(ListNode* head) {
    // Sanity check
    if (!head) {
        return head;
    }

    ListNode* next = head->next;
    ListNode* next_next = nullptr;
    
    // Head becomes tail after reverse
    head->next = nullptr;

    while (next) {
        // Save prev states
        next_next = next->next;
        
        // Reverse
        next->next = head;
        
        // Update states
        head = next;
        next = next_next;
    }

    return head;
}
