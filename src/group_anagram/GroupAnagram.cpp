#include <vector>
#include <unordered_map>
#include <string>
#include <array>
#include <cmath>

using namespace std;

namespace {
unordered_map<char,int> getStringMakeup(string s) {
    unordered_map<char,int> makeup;

    for (const auto& c : s) {
        // Found
        if (makeup.count(c)) {
            makeup[c]++;
        } else {
            makeup[c] = 1;
        }
    }

    return makeup;
}

bool isAnagram(unordered_map<char,int> makeup, string s2) {
    for (const auto& c : s2) {
        // Found
        if (makeup.count(c)) {
            if (makeup[c] == 1) {
                makeup.erase(c);
            } else {
                makeup[c]--;
            }
        } else {
            return false;
        }
    }

    // Not using up makeup
    if (!makeup.empty()) {
        return false;
    }

    return true;
}
}

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
