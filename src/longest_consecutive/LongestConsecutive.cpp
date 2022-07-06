#include <vector>
#include <unordered_map>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    std::unordered_map<int,int> hm;
    
    for (const auto &x : nums)
    {
        hm.insert(std::pair<int,int> (x,1));
    }
                    
    int max_len = 0;
    int len = 0;
    for (const auto &x : nums) {
        // New sequence
        if (hm[x] == 1) {
            int g = x;
            int l = x - 1;

            // Search forward
            while (hm.find(g) != hm.end()) {
                hm[g] = 2;
                g++;
                len++;
            }
            
            // Search backward
            while (hm.find(l) != hm.end()) {
                hm[l] = 2;
                l--;
                len++;
            }
            
            if (len > max_len) {
                max_len = len;
            }
        
        // Already examined sequence
        } else if (hm[x] == 2) {
            continue;
        }
        
        len = 0;
    }

    return max_len;
}
