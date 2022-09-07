#include <stack>
#include <vector>
#include "LinkedList.hpp"

using namespace std;

ListNode* mergeTwoList(ListNode* list1, ListNode* list2) {
    ListNode* merge_list_head = nullptr;
    ListNode* prev = nullptr;

    while (list1 || list2) {
        ListNode* new_node = nullptr;
        
        int val1 = INT32_MAX;
        int val2 = INT32_MAX;

        if (list1) {
            val1 = list1->val;
        }

        if (list2) {
            val2 = list2->val;
        }

        if (val1 < val2) {
            new_node = list1;
            list1 = list1->next;
        } else {
            new_node = list2;
            list2 = list2->next;
        }

        if (!merge_list_head) {
            merge_list_head = new_node;
        } else {
            prev->next = new_node;
        }

        prev = new_node;
    }

    return merge_list_head;
}

/**
 * \Trick   The second half of merge sort
 * \Time    O(nlogk), with n as the average list length and k as number of lists
 * \Space   O(k)
 * \Ref     Neetcode
 */
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) {
        return nullptr;
    }
    
    vector<ListNode*> in_lists = lists;
    vector<ListNode*> merge_lists;
    stack<int> i_empty_list;

    // Remove empty lists
    int i = 0;
    for (auto list : in_lists) {
        if (!list) {
            i_empty_list.push(i);
        }
        i++;
    }

    while (!i_empty_list.empty()) {
        // delete in_lists[i_empty_list.top()];
        in_lists.erase(in_lists.begin() + i_empty_list.top());
        i_empty_list.pop();
    }

    // ListNode* prev_node = nullptr;
    vector<ListNode*>* p_in_lists = &in_lists;
    vector<ListNode*>* p_merge_lists = &merge_lists;

    while (p_in_lists->size() > 1) {
        p_merge_lists->clear();
        size_t i = 0;
        for (; i < p_in_lists->size() - 1; i += 2) {
            p_merge_lists->push_back(
                mergeTwoList((*p_in_lists)[i], (*p_in_lists)[i + 1]));
            // delete (*p_in_lists)[i];
            // delete (*p_in_lists)[i + 1];
        }

        if (i == p_in_lists->size() - 1) {
            p_merge_lists->push_back((*p_in_lists)[i]);
            // delete (*p_in_lists)[i];
        }

        // Swap the pointers
        vector<ListNode*>* tmp = p_in_lists;
        p_in_lists = p_merge_lists;
        p_merge_lists = tmp;
    }

    return (*p_in_lists)[0];
}
