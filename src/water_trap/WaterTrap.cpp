#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * \Trick   Two pointer technique with the observation that the water trapped at 
 *          any point i can be determined by 
 *          min(max_left, max_right) = min(max(h[0:i-1]), max(h[i+1:n]). We can 
 *          just calculate the max left and max right values for each position 
 *          in O(n) and then use O(n) space to store it.
 * 
 *          There's another trick to reduce the space complexity down to O(1) 
 *          based on the attribute of min function: min(a,b) <= a and 
 *          min(a,b) <= b. We start algorithm by using two pointers l and r 
 *          pointing to two ends of the array and maintaining max_left and 
 *          max_right values. Observe that the tmp max_right of h[l] might not 
 *          be the true max_right and so is the tmp max_left of h[r] because 
 *          the entire has yet to be considered. However, we don't need to these  
 *          true values because we only need the min value.
 * 
 *          For example, suppose that max_left < max_right, then we can compute 
 *          the amount of water at l because min(max_left, max_right) = max_left, 
 *          observing that the true max right of h[l] >= max_right and the 
 *          current max_left is already the true max_left of h[l]. We can just 
 *          calculated the water trapped at h[l] and increment the l pointer. 
 *          Do the same for the right pointer until they meet.
 *          
 * \Time    O(n)
 * \Space   O(1)
 * \Ref     Neetcode
 */
int trap(vector<int>& height) {
    int l = 0;
    int r = height.size() - 1;
    int max_left = 0;
    int max_right = 0;
    int trap_water = 0;

    while (l <= r) {
        int water_level = min(max_left, max_right);

        if (water_level == max_left) {
            if (water_level > height[l]) {
                trap_water += (water_level - height[l]);
            }

            if (height[l] > max_left) {
                max_left = height[l];
            }
            l++;
        } else {
            if (water_level > height[r]) {
                trap_water += (water_level - height[r]);
            }

            if (height[r] > max_right) {
                max_right = height[r];
            }
            r--;
        }
    }

    return trap_water;
}
