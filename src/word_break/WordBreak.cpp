#include <string>
#include <vector>
#include <unordered_set>
#include <stack>

using namespace std;

/**
 * \Time    O(|A|*|B|*l) with l is the average length of B.
 * \Space   -
 * \Trick   Similar as depth-first search
 * \Ref     -
 */
int wordBreak(string A, vector<string> &B) {
    stack<size_t> p;
    auto str_len = A.length();
    unordered_set<size_t> visit; // List of already visited indices
    
    p.push(0);
    
    while (!p.empty()) {
        size_t i = p.top();
        p.pop();
        
        // Not visit yet
        if (!visit.count(i)) {
            for (const auto& s : B) {
                auto j = i;
                bool is_match = true;
                
                for (const auto& c : s) {
                    if (c != A[j]) {
                        is_match = false;
                        break;
                    } else {
                        j++;
                    }
                }
                
                // Reach the end of the string
                if (j == str_len) {
                    return 1;
                }

                if (is_match) {
                    // Add next position if it has not been examined
                    if (!visit.count(j)) 
                        p.push(j);
                }
                
                // Mark as visit
                visit.insert(i);
            }
        }
        
    }
    
    return 0;
}
