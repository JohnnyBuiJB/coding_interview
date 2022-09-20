#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
public:    
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    // ~ListNode() {
    //     ListNode* cur = this;

    //     while (cur) {
    //         ListNode* next = cur->next;
    //         delete cur;

    //         cout << "Delete node " << cur << endl;

    //         cur = next;
    //     }
    // }
};

ListNode* create_linked_list(vector<int> values);
void delete_linked_list(ListNode* head);
ListNode* find_node(ListNode* head, int val);

// Linked list with random pointers, referenced from Leetcode
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

void delete_random_linked_list(Node* head);
Node* create_random_linked_list(vector<int> values);

struct DoublyLinkedNode {
    int value;
    DoublyLinkedNode* next = nullptr;
    DoublyLinkedNode* prev = nullptr;

    DoublyLinkedNode(int val) : value(val) {};
};

class DoublyLinkedList {
    DoublyLinkedNode* head = nullptr;
    DoublyLinkedNode* tail = nullptr;
    int mSize = 0;

public:
    DoublyLinkedList() {};

    ~DoublyLinkedList() {
        bool succeed = true;
        while (succeed) {
            succeed = this->pop_front();
        }
    };

    // Get head of the list
    DoublyLinkedNode* front();

    // Get tail of the list
    DoublyLinkedNode* back();

    // Delete head node
    bool pop_front();

    // Insert at tail
    void push_back(int value);

    // Erase a random node in the list
    // Assume that the node belongs to the list
    void erase_node(DoublyLinkedNode* node);

    // Insert a node after another node in the list
    // Assume that the nodes belongs to the list
    bool insert_after(DoublyLinkedNode* newNode, DoublyLinkedNode* pos);

    // Check if the list is empty
    bool empty();

    // Find a node with a certain value. Return the first node found
    DoublyLinkedNode* find_node(int val);

    // TODO: implement using iterator
    // DoublyLinkedNode* begin() {return head;};
    // DoublyLinkedNode* end() {return tail;};
};

DoublyLinkedList* create_doubly_linked_list(vector<int> values);
