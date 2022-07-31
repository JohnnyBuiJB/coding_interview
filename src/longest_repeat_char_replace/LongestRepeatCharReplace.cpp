#include <string>
#include <array>

using namespace std;

/**
 * \Trick   Sliding window with the number of required replacement (n_rep) as its 
 *          attribute. To be valid, a substring has to have n_rep not greater 
 *          than k.
 *          Proof: the only way to reduce the n_rep of the substring is to 
 *          shrink it from the left. We are gonna prove that extending the 
 *          substring to the right does not reduce it n_rep.
 *          
 *          Suppose that a string has the x dominant letters, y candidate 
 *          dominant letters and z other letters, with the n_rep being y + z. If 
 *          we extend the substring to the right, 2 cases can happen:
 *          1. y' = y + 1 < x. The dominant letter remains the same so 
 *          n_rep' = y + 1 + z > n_rep.
 *          2. y' > x. The cadidate dominant letter becomes the dominant letter. 
 *          n_rep' = x + z > n_rep = y + z
 *          In both cases, n_rep does not decrease, which concludes the proof.
 * 
 * \Time    O(n), with n being the length of the string
 * \Space   O(1), keep the counts of the letters.
 * \Ref     Bui V.
 */
int characterReplacement(string s, int k) {
    // Character counts of the current substring
    array<int, 26> count = {0};   // Only uppercase English letters
    int l = 0;
    int r = 0;
    int max_ss_len = 1;
    int cur_ss_len = 1;
    count[s[r] - 'A']++;
    char dom_let = s[r];    // The dominant letter of the substring
    int dom_let_cnt = 1;    // Dominant letter count
    int n_rep = 0;          // Number of replaced letters
    
    int str_len = s.size();
    while (r < str_len - 1) {
        // Add new letter to the current substring
        r++;
        char new_let = s[r];
        count[new_let - 'A']++;
        cur_ss_len++;
        
        // New possible dominant letter
        if (new_let != dom_let) {
            if (count[new_let - 'A'] > dom_let_cnt) {
                // Update current dominant letter
                dom_let = new_let;
                dom_let_cnt = count[new_let - 'A'];
            }

            n_rep = cur_ss_len - dom_let_cnt;
            
            // Maintain non-negative k
            while (n_rep > k) {
                char rmv_let = s[l];
                l++;
                cur_ss_len--;

                // Shrink the substring from the left
                count[rmv_let - 'A']--;

                if (rmv_let == dom_let) {
                    dom_let_cnt--;

                    // Update the dominant letter
                    int i = 0;

                    for (auto it = count.begin(); it != count.end(); it++ ) {
                        if (*it > dom_let_cnt) {
                            dom_let_cnt = *it;
                            dom_let = static_cast<char>('A' + i);
                            break;
                        }
                        i++;
                    }
                }

                n_rep = cur_ss_len - dom_let_cnt;
            }
        } else {
            dom_let_cnt++;
        }
        
        if (cur_ss_len > max_ss_len) {
            max_ss_len = cur_ss_len;
        }
    }
    
    return max_ss_len;
}
