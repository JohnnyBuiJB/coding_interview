#include <iostream>
#include <vector>

using namespace std;

/**
 * \Trick   Break the problem down to 2 subproblems, searching for the pivot and 
 *          search for the target. Input array can be broken by 2 portions, 
 *          L and R with min(L), L[0], is greater than any value of R. Pivot is 
 *          R[0] or min(R).
 * 
 *          Note that the input array can be rotated or not.
 * \Time    O(logn)
 * \Space   O(1)
 * \Ref     Bui V.
 */
int search(vector<int>& nums, int target) {
    // l always points into L and r always points into R
    int l = 0;
    int n = nums.size();
    int r = n - 1;
    int m = 0;
    
    bool is_rotated = nums[n - 1] < nums[0];
    
    if (is_rotated) {
        int i_pivot = -1;
        
        while (l < r - 1) {
            m = (l + r) / 2;
            
            if (m == 0) {
                if (nums[m] < nums[m + 1]) {
                    i_pivot = m;
                    break;
                }
            } else if (m == n - 1) {
                if (nums[m] < nums[m - 1]) {
                    i_pivot = m;
                    break;
                }
            } else {
                if (nums[m] < nums[m - 1] && nums[m] < nums[m + 1]) {
                    i_pivot = m;
                    break;
                }
            }
            
            // mid falls into L
            if (nums[m] > nums[r]) {
                l = m;
            } else {
                r = m;
            }
        }

        if (i_pivot == -1) {
            i_pivot = r;
        }
        
        // Binary search in appropriate partition
        if (target > nums[n - 1]) {
            l = 0;
            r = i_pivot - 1;
        } else {
            l = i_pivot;
            r = n - 1;
        }
    }
    
    while (l <= r) {
        m = (l + r) / 2;

        if (nums[m] == target) {
            return m;
        } else if (nums[m] > target) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    
    return -1;
}
