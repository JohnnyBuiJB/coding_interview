#include <cstdint>
#include <unordered_set>

#include "LinkedList.hpp"

using namespace std;

Node* copyRandomList(Node* head) {
    // Sanity check
    // Empty list
    if (!head) {
        return nullptr;
    }
    
    // Create new list
    Node* orig = head;  // pointer to original list
    unordered_set<Node*,Node*> addr_map;
    Node* copy_head = nullptr;
    Node* copy_prev = nullptr;

    while (orig) {
        Node* new_node = new Node(orig->val);
        
        if (!copy_head) {
            copy_head = new_node;
        }

        // Save maps of nodes' addr for random access later
        addr_map[static_cast<uint64_t>(orig)] = new_node;

        if (copy_prev) {
            copy_prev->next = new_node;
        }
        
        copy_prev = new_node;
        orig = orig->next;
    }
    
    // Connect random pointers
    orig = head;
    Node* copy = copy_head;

    while (orig) {
        copy->random = addr_map(orig->random);
        
        orig = orig->next;
        copy = copy->next;
    }

    return copy_head;
}