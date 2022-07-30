#include <string>
#include <unordered_map>

using namespace std;

/**
 * \Trick   Sliding window, if the attribute as the counts of characters stored 
 *          in a hash table.
 * \Time    O(|s1| + |s2|), one pass through s1 and one pass through s2.
 * \Space   O(s1), the hash table
 * \Ref     Reference
 */
bool checkInclusion(string s1, string s2) {
    // Substring length
    int s1_len = s1.size();
    int s2_len = s2.size();

    if (s1_len > s2_len) {
        return 0;
    }
    
    unordered_map<char,int> s1_makeup;
    
    for (const auto& c : s1) {
        if (s1_makeup.count(c)) {
            s1_makeup[c]++;
        } 
        // New character
        else {
            s1_makeup[c] = 1;
        }
    }
    
    // Compare the first s2's substring from the left
    for (int i = 0; i < s1_len; i++) {
        if (s1_makeup.count(s2[i])) {
            s1_makeup[s2[i]]--;
        } 
        // New character
        else {
            s1_makeup[s2[i]] = -1;
        }
        
        if (s1_makeup[s2[i]] == 0) {
            s1_makeup.erase(s2[i]);
        }
    }
    
    if (s1_makeup.empty()) {
        return true;
    }
    
    // Check the makeup of all s2 substrings of s1's length
    int l = 0;
    int r = l + s1_len - 1;
    
    while (r < s2_len - 1) {
        // Shift the substring to the right by 1 character and update 
        // the makeup
        // Exclude the leftmost char
        s1_makeup[s2[l]]++;
        
        // Remove zero-count char from the hash table
        if (s1_makeup[s2[l]] == 0) {
            s1_makeup.erase(s2[l]);
        }
        
        // Include new char afther the rightmost char
        if (s1_makeup.count(s2[r + 1])) {
            s1_makeup[s2[r + 1]]--;
            
            if (s1_makeup[s2[r + 1]] == 0) {
                s1_makeup.erase(s2[r + 1]);
            }
        } 
        // Unmatched char
        else {
            s1_makeup[s2[r + 1]] = -1;
        }
        
        if (s1_makeup.empty()) {
            return true;
        }
        
        // Update pointers
        l++;
        r++;
    }
    
    return false;
}
