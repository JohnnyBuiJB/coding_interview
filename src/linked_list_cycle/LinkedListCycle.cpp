#include "LinkedList.hpp"

using namespace std;

/**
 * \Trick   Floyd's tortoise and hare algorithm
 * 
 *          The idea is to let a tortoise (slow) and a hare to race in the 
 *          linked list. The hare is twice as fast as the tortoise. If there 
 *          exists a cycle in the list, they will meet at some point in time.
 * 
 * \Time    O(m + n - k) where m is the trail before the cycle, n is the length 
 *          of the cycle, and k is the position of the hare when the tortoise 
 *          enters the cycle
 * 
 *          Observation 1: k = m mod n. The tortoise takes m steps to reach the 
 *          cycle. At the same time, the hare already goes a distance of 2m and 
 *          the later m distance is within the cycle, hence, k = m mod n.
 *          
 *          Observation 2: the hare will catch up with the tortoise after n - k 
 *          steps after the tortoise enters the cycle because the speed 
 *          difference between them is 1 and n - k is the distance difference 
 *          between them.
 * \Space   O(1)
 * \Ref     Bui V.
 */
bool hasCycle(ListNode *head) {
    // Empty list
    if (!head) {
        return 0;
    }

    // Only contains 1 node
    if (!head->next) {
        return 0;
    }

    ListNode* p_s = head->next;     // slow pointer
    ListNode* p_f = p_s->next;      // fast pointer
    
    while (p_s != nullptr && p_f != nullptr) {
        if (p_s == p_f) {
            return 1;
        } else {
            p_s = p_s->next;

            if (p_f->next) {
                p_f = p_f->next->next;
            } else {
                return 0;
            }
            
        }
    }

    return 0;
}