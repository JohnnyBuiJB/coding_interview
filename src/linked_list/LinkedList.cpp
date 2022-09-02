#include "LinkedList.hpp"
#include <memory> // smart pointer

void delete_linked_list(ListNode* head) {
    while (head) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
    
    // // Precondition
    // if (head == nullptr) {
    //     return;
    // }
    
    // // Multiple nodes
    // if (head->next != nullptr) {
    //     // Delete the tail list
    //     delete_linked_list(head->next);

    //     // Unlink
    //     head->next = nullptr;

    //     return delete_linked_list(head);
    // } 
    // // Only one node
    // else {
    //     delete head;
    // }
};

ListNode* create_linked_list(vector<int> values) {
    ListNode* head = nullptr;
    ListNode* prev = nullptr;
    if (!values.empty()) {
        head = prev = new ListNode(values[0]);

        auto it = values.begin();
        it++;
        for (; it != values.end(); it++) {
            ListNode* node = new ListNode(*it);

            prev->next = node;
            prev = node;
        }
    }
    
    return head;
}

ListNode* find_node(ListNode* head, int val) {
    while (head) {
        if (head->val == val) {
            return head;
        }
        head = head->next;
    }

    return nullptr;
}
