#include <cstdbool>
#include <string>
#include <unordered_map>

bool isPalindromePermutation(std::string s) {
    // Init hm
    std::unordered_map<std::string,size_t> hm;

    for (const auto &c : s) {
        // Only concern lowercase characters
        if (c > 'a' && c < 'z') {
            std::string tmp(1,c);
            hm[tmp] += 1;
        }
    }

    size_t n_odd = 0;

    // Check characters with odd occurences
    for (const auto &x : hm) {
        if (x.second % 2 == 1) {
            n_odd++;
        }

        if (n_odd > 1) {
            return false;
        }
    }

    return true;
}
