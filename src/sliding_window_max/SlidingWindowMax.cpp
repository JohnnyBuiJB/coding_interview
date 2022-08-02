#include <vector>
#include <deque>

using namespace std;

/**
 * \Trick   Sliding window, with the attribute as a deque of peaks. This 
 *          attribute is used to eliminate useless comparisons when looking for 
 *          max value of a window, which takes O(k) by brute force.
 *          
 *          Observe that for x[i] and x[i+1], if x[i+1] appears in a window 
 *          with x[i], for example window x[i-2:i+2], then x[i+1] will appear 
 *          in all of the successor windows containing x[i]. Notice that if 
 *          x[i+1] > x[i], then we don't need to check the value of x[i] in the 
 *          max search for these successor windows. This helps eliminate useless 
 *          comparisons.
 *          
 *          However, we still need to keep track of smaller successors because 
 *          the max value might be gone before the its successors when the 
 *          window slides.
 *          
 *          As a result, we use a deque to keep 2 pieces of information: the 
 *          current max value and potential successor max values. Notice that 
 *          the deque is always monotonically decreasing.
 * \Time    O(n)
 * \Space   O(n)
 * \Ref     Neetcode
 */
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> maxes;
    deque<int> max_vals;
    int l = 0;
    int r = 1;

    // To avoid empty check
    max_vals.push_front(nums[0]);

    // Check the leftmost k-long window
    for (; r < k; r++) {
        int new_val = nums[r];

        // New max
        if (new_val > max_vals.front()) {
            max_vals.clear();
            max_vals.push_front(new_val);
        } 
        // New potential successor max
        else {
            while (new_val > max_vals.back()) {
                max_vals.pop_back();
            }
            max_vals.push_back(new_val);
        }
    }

    maxes.push_back(max_vals.front());

    // Slide the window
    int n_nums = nums.size();
    while (r < n_nums) {
        // Extend the window to the right
        int new_val = nums[r];

        // New max
        if (new_val > max_vals.front()) {
            max_vals.clear();
            max_vals.push_front(new_val);
        } 
        // New potential successor max
        else {
            while (new_val > max_vals.back()) {
                max_vals.pop_back();
            }
            max_vals.push_back(new_val);
        }

        // Shrink the window from the left
        int rmv_val = nums[l];

        if (rmv_val == max_vals.front()) {
            max_vals.pop_front();
        }

        maxes.push_back(max_vals.front());

        // Shift the window
        r++;
        l++;
    }

    return maxes;
}
