#include <vector>
#include <unordered_map>
#include <string>
#include <array>
#include <cmath>

using namespace std;

class ArrayHash {
public:
    size_t operator()(const array<int,26> key) const {
        size_t ret = 0;

        size_t i = 1;
        for (const auto& n : key) {
            ret += n * static_cast<size_t>(pow(5,i));
            i++;
        }
        
        return ret;
    }
};

/*
Time:   O(nm) with n is the number of strings and m is the average length 
        of each string
Idea:   Use the make up of the string as key -> strings with the same makeup 
        are anagrams. This implementation uses an array[26] to represent 
        the make up, which requires a custom hash function.
*/
vector<vector<string> > groupAnagrams(vector<string>& strs) {
    unordered_map< array<int,26>, vector<string>, ArrayHash > hm;

    for (const auto& s : strs) {
        // Count character population
        array<int,26> cnt = {0};
        for (const auto& c : s) {
            cnt[c - 'a']++;
        }
        
        hm[cnt].push_back(s);
    }

    vector< vector<string> > ans;

    for (auto it = hm.begin(); it != hm.end(); it++) 
    {
        vector<string> tmp;
        
        for (auto str : it->second) {
            tmp.push_back(str);
        }

        ans.push_back(tmp);
    }

    return ans;
}
