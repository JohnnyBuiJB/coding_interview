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
