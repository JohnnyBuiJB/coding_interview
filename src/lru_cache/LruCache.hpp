#include <list>
#include <unordered_map>

using namespace std;

struct DoubleLinkedNode;

struct DoubleLinkedNode {
    int value;
    DoubleLinkedNode* next = nullptr;
    DoubleLinkedNode* prev = nullptr;

    DoubleLinkedNode(int val) : value(val) {};
};

struct Item {
    int value;
    DoubleLinkedNode* addr;
    
    Item() {};
    Item(int val, DoubleLinkedNode* address) : value(val), addr(address) {};
};

class DoubleLinkedList {
    DoubleLinkedNode* head = nullptr;
    DoubleLinkedNode* tail = nullptr;
    int mSize = 0;

public:
    DoubleLinkedList() {};

    ~DoubleLinkedList() {
        bool succeed = true;
        while (succeed) {
            succeed = this->pop_front();
        }
    };

    DoubleLinkedNode* front() {
        return head;
    };

    DoubleLinkedNode* back() {
        return tail;
    };

    bool pop_front() {
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

    void push_back(int value) {
        DoubleLinkedNode* new_node = new DoubleLinkedNode(value);
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

    void erase_node(DoubleLinkedNode* node) {
        // Sanity check
        if (!node) {
            return;
        }

        // Assume that the node belongs to the list
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

    bool empty() {
        return (mSize == 0);
    };
};

/**
 * \Trick   Using Doubly Linked List to keep track of the list of LRU values. 
 *          
 *          The head of the list points to the LRU and the tail points to MRU. 
 *          This allows acquiring LRU and adding new value as MRU in constant 
 *          time.
 * 
 *          At the same time, use a hash map to keep the values, and more 
 *          importantly, the addresses of the nodes in the LRU list. This helps 
 *          locate and remove the value from the LRU in constant time, thank to 
 *          doubly linked list's features.
 *          
 * \Time    O(1) for all methods
 * \Space   O(c) with c as the capacity of the cache
 * \Ref     Bui V.
 */
class LRUCache {
private:
    unordered_map<int, Item>* mpMap;
    DoubleLinkedList* mpLRUList;
    int mCap;
    int mSize = 0;

public:
    LRUCache(int capacity) : mCap(capacity) {
        // Init map and LRU
        mpLRUList = new DoubleLinkedList();
        mpMap = new unordered_map<int, Item>;
    };

    ~LRUCache() {
        mpMap->clear();

        delete mpMap;
        delete mpLRUList;
    };
    
    int get(int key) {
        int result = -1;
        
        // Search for key
        if (mpMap->count(key)) {
            result = (*mpMap)[key].value;
            
            // // Update LRU
            mpLRUList->erase_node((*mpMap)[key].addr);
            mpLRUList->push_back((*mpMap)[key].value);
            (*mpMap)[key].addr = mpLRUList->back();
        }
        
        return result;
    };
    
    void put(int key, int value) {
        // Search for key
        if (mpMap->count(key)) {
            // Update value
            (*mpMap)[key].value = value;
        } else {
            // Exceed capacity
            if (mSize >= mCap) {
                // Search for and evict LRU
                // LRU is guaranteed to be non-empty in this case
                auto lru_node = mpLRUList->front();
                mpMap->erase(lru_node->value);
                mpLRUList->pop_front();
            } else {
                mSize++;
            }

            // Add new item
            mpLRUList->push_back(value);
            auto temp = Item(value, mpLRUList->back());
            (*mpMap)[key] = temp;
        }
    };
};
