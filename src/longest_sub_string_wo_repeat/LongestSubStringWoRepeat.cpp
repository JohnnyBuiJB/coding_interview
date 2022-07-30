#include <string>
#include <unordered_set>

using namespace std;

/**
 * \Trick   Use two pointers l and r to mark the substring. Build a hash table 
 *          with keys as makeup of the current substring. Extend the substring 
 *          to the right gradually and check for repetition. If there is 
 *          repetition, shrinks the substring from the left side until there is 
 *          not any repetition.
 * \Time    O(n) because l and r always move in only one way towards the end of 
 *          the string. In the worst case in which both l and r have to move to 
 *          the end of the string, it takes only 2|s| or O(n) to do so.
 * \Space   O(n) we might need to construct a hash table of n keys in case all 
 *          of the characters in the string are different.
 * \Ref     Bui V.
 */
int lengthOfLongestSubstring(string s) {
    // Empty string
    if (s.size() == 0) {
        return 0;
    }

    int l = 0;
    int r = 0;
    
    // Set of characters in the current substring s[l:r-1]
    unordered_set<char> makeup;
    int max_len = 1;
    int cur_len = 1;
    
    makeup.insert(s[0]);
    
    while (r < s.size() - 1) {
        // Extend the substring
        r++;
        cur_len++;
        
        // Check for repetition
        // This condition guarantees that l will be always 
        // less than or equal r
        while (makeup.count(s[r])) {
            // Shrink the substring towards the right
            makeup.erase(s[l]);
            l++;
            cur_len--;
        }

        makeup.insert(s[r]);
        
        // Update max len
        if (cur_len > max_len) {
            max_len = cur_len;
        }
    }
    
    return max_len;
}
