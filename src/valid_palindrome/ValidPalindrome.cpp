#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

static inline bool isAlphanumeric(char c) {
    if ((c >= 'a' && c <= 'z') 
        || (c >= 'A' && c <= 'Z')
        || (c >= '0' && c <= '9')) {
        return true;
    }
    
    return false;
}

bool isPalindrome(string s) {
    // There are two cases: even and odd length.
    // However, we can't know which case in advance because 
    // of the unknown number of non-alphanumeric characters
    int l = 0;
    int r = s.size() - 1;
    constexpr int cap_gap = 'a' - 'A';
    
    // b == e and b > e are terminating conditions, indicating 
    // the cross of the half point
    while (l < r) {
        char l_let = s[l];
        char r_let = s[r];
        
        // Skip non-alphanumeric letters
        if (!isAlphanumeric(l_let)) {
            l++;
            continue;
        }
        
        if (!isAlphanumeric(r_let)) {
            r--;
            continue;
        }

        // Convert to lower case
        if (l_let >= 'A' && l_let <= 'Z') {
            l_let += cap_gap;
        }
        
        if (r_let >= 'A' && r_let <= 'Z') {
            r_let += cap_gap;
        }

        if (l_let != r_let) {
            return false;
        }
        
        l++;
        r--;
    }
    
    return true;
}
