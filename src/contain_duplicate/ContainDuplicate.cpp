#include <unordered_map>
#include <vector>

bool containDuplicate(std::vector<int> nums) {
    std::unordered_map<int,bool> hm;

    for (const auto &x : nums) {
        // New key
        if (hm.find(x) == hm.end()) {
            hm.insert(std::pair<int,int> (x,false));
        } else {
            return true;
        }
    }
    
    return false;
}
