#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * \Trick   Using sliding window technique, with the attribute as validity. The 
 *          window is valid when it contains all letters in t (including 
 *          duplicates). To make the validity check constant time, we separate 
 *          it into 2 phases:
 *          - Phase 1: when finding the leftmost valid substring. Notice that 
 *          if there always exists a leftmost valid substring if there exists 
 *          a valid substring. In this phase, we use the hash map empty method 
 *          to check the validity in constant time.
 *          Because a valid window does not necessarily contain the 
 *          exact count of letters in t, but it can contain more than that. For 
 *          example, "cabc" is a valid window with t = "abc". Hence, the empty 
 *          method cannot be used anymore. We divide the counts of the 
 *          substring into 2 hash maps, one containing the bare minimum needed 
 *          letter counts, the other containing excessive letter counts.
 *          
 *          - Phase 2: subtract letter counts in the excessive letter counts 
 *          when minimizing the substring (shrink it from the left) but still 
 *          keep it valid. Because there will be at most O(n) minimizing passes 
 *          (we can only increment the left pointer n times), the amortized time 
 *          complexity of this process is O(n).
 * 
 * \Time    O(n + m), where n = |s| and m = |t|
 * \Space   O(m), hash maps and hash set for letters in t
 * \Ref     Bui V.
 */
string minWindow(string s, string t) {
    int s_len = s.size();
    int t_len = t.size();
    
    if (t_len > s_len) {
        return string();
    }
    
    unordered_set<char> let_set;        // Set of needed letters
    
    // The count of the current substring = let_cnt + excess_let_cnt
    // Let_cnt is used to check valid string quickly, in linear time
    unordered_map<char,int> let_cnt;    // Count of needed letters
    unordered_map<char,int> excess_let_cnt;    // Count of excessive needed letters
    
    // Build letter counts of t in O(m)
    for (const auto& c : t) {
        let_set.insert(c);
        
        if (let_cnt.count(c)) {
            let_cnt[c]--;   // Negative count indicates the need of more occurences
        } else {
            let_cnt[c] = -1;
        }
    }
    
    // Search for minimal valid substring
    int l = 0;
    int r = 0;
    int l_min_ss = -1;
    int r_min_ss = -1;
    int cur_len = 1;
    int min_len = s_len;
    bool is_valid = false;
    
    while (r < s_len) {
        char new_let = s[r];
        
        // Search for the leftmost valid substring, O(1)
        if (!is_valid) {
            // Needed letter
            if (let_set.count(new_let)) {
                // Still need
                if (let_cnt.count(new_let)) {
                    let_cnt[new_let]++;
                } 
                // Excessive
                else {
                    if (excess_let_cnt.count(new_let)) {
                        excess_let_cnt[new_let]++;
                    } else {
                        excess_let_cnt[new_let] = 1;
                    }
                }
            }

            // Check if there are enough
            if (let_cnt[new_let] == 0) {
                let_cnt.erase(new_let);
            }

            // Valid check
            if (let_cnt.empty()) {
                is_valid = true;
                min_len = cur_len;
                l_min_ss = l;
                r_min_ss = r;
            }
        } 
        // Extending the valid substring to the right, resulting in another 
        // valid substring, O(1)
        else {
            if (let_set.count(new_let)) {
                if (excess_let_cnt.count(new_let)) {
                    excess_let_cnt[new_let]++;
                } else {
                    excess_let_cnt[new_let] = 1;
                }
            }
        }
        
        // Minimize the substring
        bool is_minimized = false;
        while (is_valid && l <= r) {
            is_minimized = true;
            
            // Exclude the leftmost letter of the substring
            char rmv_let = s[l];
            l++;
            cur_len--;
            
            // Remove one of the needed letters
            if (let_set.count(rmv_let)) {
                // Redundant
                if (excess_let_cnt.count(rmv_let)) {
                    if (excess_let_cnt[rmv_let] <= 0) {
                        is_valid = false;
                    } else {
                        excess_let_cnt[rmv_let]--;
                    }
                } else {
                    is_valid = false;
                }
            }
        }

        // Undo the minimization step that makes the substring invalid
        if (is_minimized) {
            l--;
            cur_len++;
            is_valid = true;
        }
        
        // Update the length of min substring
        if (cur_len < min_len) {
            min_len = cur_len;
            l_min_ss = l;
            r_min_ss = r;
        }
        
        // The substring is guarantied to be valid after each extention to the right
        r++;
        cur_len++;
    }
    
    // Remove the increase of substr length in the final pass
    cur_len--;
    
    if (is_valid) {
        return string(s, l_min_ss, r_min_ss - l_min_ss + 1);
    } else {
        return string();
    }
}
