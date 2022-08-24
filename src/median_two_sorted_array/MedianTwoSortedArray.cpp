#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <limits>

using namespace std;

/**
 * \Trick   Let the first array be A, the second be B.
 * 
 *          Observation 1: the median divides the merged array into 2 sub arrays 
 *          , L and R. More importantly, the size of L and R can be determined 
 *          at the beginning by divide the total size by 2.
 * 
 *          Observation 2: let a partition be the split of A into A_left and 
 *          A_right and the split of B into B_left and B_right. A valid 
 *          partition has:
 *          1. |A_left| + |B_left| = |L| = total_len / 2
 *          2. A_left.back() < B_right.front()
 *          3. B_left.back() < A_right.front()
 * 
 *          2 and 3 guarantees that A_left and B_left only contains all L's 
 *          elements.
 * 
 *          We can apply binary search on one array (pick the shorter) and 
 *          search for the valid partition element. The partition element on A 
 *          can be used to infer the partition element on B by the known |L|. 
 *          Then check conditions 2 and 3 to ensure that no other elements fall 
 *          into the L.
 * 
 *          If the valid partition element on A does not exist, then there is no 
 *          partition of A and all L's elements go to B.
 *          
 * \Time    O(min(m,n))
 * \Space   O(1)
 * \Ref     Neetcode
 */
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int median_1 = 0;
    int median_2 = 0;
    int nums1_len = nums1.size();
    int nums2_len = nums2.size();
    int total_len = nums1_len + nums2_len;
    int half_len = total_len / 2;
    int i_l = 0;
    int i_r = nums1_len - 1;
    int i_m = 0;
    int nums2_left = 0;
    int is_total_len_odd = total_len % 2 == 1;
    
    int nums1_l_max = 0;
    int nums1_r_min = 0;
    int nums2_l_max = 0;
    int nums2_r_min = 0;

    if (nums1_len == 0) {
        if (is_total_len_odd) {
            median_1 = median_2 = nums2[nums2_len / 2];
        } else {
            median_1 = nums2[nums2_len / 2 - 1];
            median_2 = nums2[nums2_len / 2];
        }

        return static_cast<double>(median_1 + median_2) / 2;
    } else if (nums2_len == 0) {
        if (is_total_len_odd) {
            median_1 = median_2 = nums1[nums1_len / 2];
        } else {
            median_1 = nums1[nums1_len / 2 - 1];
            median_2 = nums1[nums1_len / 2];
        }

        return static_cast<double>(median_1 + median_2) / 2;
    }

    while (i_l <= i_r) {
        i_m = (i_l + i_r) / 2;
        nums2_left = half_len - i_m - 1;

        nums1_l_max = nums1[i_m];
        
        // nums1 right is not empty
        if (nums1_len > i_m + 1) {
            nums1_r_min = nums1[i_m + 1];
        } 
        else {
            // To make the later comparison always true
            nums1_r_min = INT32_MAX;
        }

        if (nums2_len >= nums2_left) {
            if (nums2_left == 0) {
                nums2_l_max = INT32_MIN;
            } else {
                nums2_l_max = nums2[nums2_left - 1];
            }

            if (nums2_len > nums2_left) {
                nums2_r_min = nums2[nums2_left];
            } else {
                // To make the later comparison always true
                nums2_r_min = INT32_MAX;
            }
        } 
        // mid value is so small that nums1_l is too few -> makes nums2_r too 
        // large
        else {
            // Set conditions to increase mid value
            nums2_l_max = INT32_MAX;
            nums2_r_min = INT32_MAX;
        }

        // Valid partition
        if (nums1_l_max <= nums2_r_min && nums2_l_max <= nums1_r_min) {
            if (is_total_len_odd) {
                median_1 = median_2 = min(nums1_r_min, nums2_r_min);
            } else {
                median_1 = max(nums1_l_max, nums2_l_max);
                median_2 = min(nums1_r_min, nums2_r_min);
            }
            break;
        } else if (nums1_l_max > nums2_r_min) {
            i_r = i_m - 1;
        } else {
            i_l = i_m + 1;
        }
    }

    // All of the left elements reside in nums2
    if (i_l > i_r) {
        nums1_l_max = INT32_MIN;
        
        // nums1 right is not empty
        if (nums1_len > 0) {
            nums1_r_min = nums1.front();
        } else {
            nums1_r_min = INT32_MAX;
        } 

        nums2_l_max = nums2[half_len - 1];

        if (nums2_len > half_len) {
            nums2_r_min = nums2[half_len];
        } else {
            nums2_r_min = INT32_MAX;
        }

        if (is_total_len_odd) {
            median_1 = median_2 = min(nums1_r_min, nums2_r_min);
        } else {
            median_1 = max(nums1_l_max, nums2_l_max);
            median_2 = min(nums1_r_min, nums2_r_min);
        }
    }

    return static_cast<double>(median_1 + median_2) / 2;
}
