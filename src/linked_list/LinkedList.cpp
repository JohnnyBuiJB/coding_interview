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

void delete_random_linked_list(Node* head) {
    while (head) {
        Node* next = head->next;
        delete head;
        head = next;
    }
};

Node* create_random_linked_list(vector<int> values) {
    Node* head = nullptr;
    Node* prev = nullptr;
    if (!values.empty()) {
        head = prev = new Node(values[0]);

        auto it = values.begin();
        it++;
        for (; it != values.end(); it++) {
            Node* node = new Node(*it);

            prev->next = node;
            prev = node;
        }
    }
    
    return head;
}


DoublyLinkedNode* DoublyLinkedList::front() {
    return head;
};

DoublyLinkedNode* DoublyLinkedList::back() {
    return tail;
};

bool DoublyLinkedList::pop_front() {
    if (mSize > 0) {
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            auto next = head->next;
            next->prev = nullptr;
            delete head;
            head = next;
        }
        mSize--;

        return true;
    }

    return false;
};

void DoublyLinkedList::push_back(int value) {
    DoublyLinkedNode* new_node = new DoublyLinkedNode(value);
    if (mSize == 0) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }

    mSize++;
};

// Assume that the node belongs to the list
void DoublyLinkedList::erase_node(DoublyLinkedNode* node) {
    // Sanity check
    if (!node) {
        return;
    }

    // Unlink the node
    auto prev = node->prev;
    auto next = node->next;

    if (prev) {
        prev->next = next;
    }

    if (next) {
        next->prev = prev;
    }

    // Update head
    if (head == node) {
        head = next;
    }

    // Update tail
    if (tail == node) {
        tail = prev;
    }

    mSize--;
};

// Assume that the nodes belongs to the list
bool DoublyLinkedList::insert_after(DoublyLinkedNode* newNode, DoublyLinkedNode* pos) {
    // Sanity check
    if (!newNode || !pos) {
        return false;
    }

    // Use push_back instead
    if (pos == tail) {
        return false;
    }

    // Insert
    auto next = pos->next;
    pos->next = newNode;
    newNode->next = next;

    next->prev = newNode;
    newNode->prev = pos;

    mSize++;

    return true;
}

bool DoublyLinkedList::empty() {
    return (mSize == 0);
};


DoublyLinkedList* create_doubly_linked_list(vector<int> values) {
    DoublyLinkedList* list = new DoublyLinkedList();
    
    for (auto& v : values) {
        list->push_back(v);
    }
    
    return list;
}

DoublyLinkedNode* DoublyLinkedList::find_node(int val) {
    DoublyLinkedNode* node = this->head;

    while (node) {
        if (node->value == val) {
            break;
        }

        node = node->next;
    }

    return node;
}
