#include <string>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t) {
    // Check length
    if (s.length() != t.length()) {
        return false;
    }
    
    // Construct characters counts
    std::unordered_map<char,int> hm;
    
    for (const auto & c : s) {
        // New character
        if (hm.find(c) == hm.end()) {
            hm.insert(std::pair<char,int> (c,1));    
        } else {
            hm[c]++;
        }
    }
    
    // Check the character distribution with the other string
    for (const auto & c : t) {
        // Found
        if (hm.find(c) != hm.end()) {
            hm[c]--;
        } else {
            return false;
        }
        
        if (hm[c] < 0) {
            return false;
        }
    }
    
    return true;
}
