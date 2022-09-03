#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "LinkedList.hpp"

using namespace std;

ListNode* reverseList(ListNode* head) {
    // Preconditions
    if (head == nullptr) {
        return nullptr;
    }
    
    ListNode* p_cur = head;
    ListNode* p_next = p_cur->next;
    p_cur->next = nullptr;
    ListNode* p_next_next = nullptr;
    
    // Preconditions: p_cur and p_next are predetermined
    while (p_next != nullptr) {
        p_next_next = p_next->next;
        
        // Reverse the link
        p_next->next = p_cur;
        
        // Move forward
        p_cur = p_next;
        p_next = p_next_next;
    }
    
    return p_cur;
}
