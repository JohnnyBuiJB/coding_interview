#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    std::unordered_map<int,int> hm;
    vector<int> ans;
    
    int i_x = 0;
    for (const auto& x : nums) {
        auto t = target - x;
        
        // Not found
        if (hm.find(t) == hm.end()) {
            hm.insert(std::pair<int,int>(x, i_x));
        }
        // Found
        else {
            return std::vector<int> {i_x,hm[t]};
        }
        
        i_x++;
    }
    // Should not reach here
    return std::vector<int> {0,0};
}
    