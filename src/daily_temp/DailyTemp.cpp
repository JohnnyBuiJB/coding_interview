#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

/**
 * \Trick   The trick is to check multiple values at the same time, and using 
 *          monotonic decreasing stack to turn that checking to only O(1). 
 *          
 *          The next warmer day temp has to be higher. When we keep all under
 *          checking days in the monotonic decreasing stack, if the new day has 
 *          lower temp than the top of the stack (lowest), then we need not to 
 *          check further, thus avoid useless comparisons.
 * \Time    O(n)
 * \Space   O(n), the stack
 * \Ref     Neetcode
 */
vector<int> dailyTemperatures(vector<int>& temperatures) {
    struct Item {
        int index;
        int temp;
    };

    // Stack of days whose the next warmer days have yet to be known
    stack<Item> pending;
    vector<int> ret;

    int i = 0;
    for (auto const &t : temperatures) {
        // Add temperary value for new day
        ret.push_back(0);   // Yet to know
        Item new_day = {i, t};

        while (!pending.empty()) {
            // Check pending days until reaching a day with higher temp
            auto top = pending.top();
            if (t > top.temp) {
                ret[top.index] = i - top.index;
                pending.pop();
            } else {
                break;
            }
        }

        pending.push(new_day);
        i++;
    }

    return ret;
}
