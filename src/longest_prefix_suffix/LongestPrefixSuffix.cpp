#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void build_dfa(string s, vector<int> &pi) {
    // Example s = abab
    int s_len = s.size();
    int k = 0;              // Number of matched letters
    
    // The first pi is always 0 because k has to be smaller than q and 
    // s1 = s[0:0]
    pi.push_back(0);

    for (int q = 1; q < s_len; q++) {
        // Check to the smaller potential prefix suffix
        char new_let = s[q];
        while (k > 0 && s[k] != new_let) {
            k = pi[k];
        }

        // Deduce from the previous prefix suffix
        // 
        // For example, s3 = aba, then pi[3] = 1 because a is the longest 
        // prefix suffix of s3. Observe that s4 = s3 + b = abab. So if the new 
        // letter matches the next letter in the pattern, pi[4] = pi[3] + 1. 
        // In this case, new letter is s[4] = b matches s[3 + 1] = b 
        // -> pi[4] = 1 + 1 = 2, which is true because ab is the longest prefix 
        // suffix of s4.
        if (s[k] == new_let) {
            k++;
        }

        pi.push_back(k);
    }
}

/**
 * \Trick   KMP algorithm
 * \Time    O(|s|)
 * \Space   O(|s|)
 * \Ref     (Stein et al., 2009, 1002)
 */
int lps(string s) {
    vector<int> pi;
    build_dfa(s, pi);

    int s_len = s.size();
    int max_len = 0;
    int k = 0;              // Number of matched letters
    
    for (int q = 1; q < s_len; q++) {
        // Check to the smaller potential prefix suffix
        char new_let = s[q];
        while (k > 0 && s[k] != new_let) {
            k = pi[k];
        }

        // Match new letter
        if (s[k] == new_let) {
            k++;
        }
    }

    return k;
}
