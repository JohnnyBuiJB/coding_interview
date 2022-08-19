#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * \Trick   Determine the potential range of eating speed and use binary search 
 *          to search for the min valid speed.
 * \Time    O(nlogm), with n as the number of piles and m as the max value of 
 *          piles
 * \Space   O(1)
 * \Ref     Neetcode
 */
int minEatingSpeed(vector<int>& piles, int h) {
    // Max of the value range
    int max_val = 0;
    int64_t sum = 0;
    
    for (auto const &p : piles) {
        sum += p;
        if (p > max_val) {
            max_val = p;
        }
    }
    
    // Min of the value range
    int l = sum / h;
    int r = max_val;
    
    int min_speed = r;

    // Binary search in the range
    while (l <= r) {
        int m = (l + r) / 2;
        int n_h = 0;
        
        if (m <= 0) {
            n_h = h + 1;
        } else {
            for (auto const &pile : piles) {
                n_h += pile / m + (pile % m != 0);
            }    
        }
        
        if (n_h <= h) {
            min_speed = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    
    return min_speed;
}
