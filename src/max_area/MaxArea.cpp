#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * \Trick   Using the Two Pointers technique. Move the pointer that points to 
 *          the min value because A = min(l,r) * width. If we move the pointer 
 *          to the max value, then the next area A' < A because w' = w - 1 and 
 *          min(h[l], h[r]) >= min(h[l+1], h[r]) (assuming that h[l] > h[r]).
 * 
 *          However, what about the combination of the eliminated and other 
 *          elements? Can one of them make the biggest area? Nope!
 * 
 *          Proof: based on the attribute of min function. min(a,b) <= a and 
 *          min(a,b) <= b. Suppose that h[l] < h[r], then min(h[l], h[r]) x w is 
 *          already the area of the biggest container that h[l] can be a part 
 *          of. Because min(h[l], k) <= h[l] with any value k, and w is the 
 *          current maximum container width. As a result, eliminating h[l] from 
 *          further examination does not affect the final result because the 
 *          area of the largest container made by h[l] is already found.
 * 
 * \Time    O(n)
 * \Space   O(1)
 * \Ref     Bui V.
 */
int maxArea(vector<int>& height) {
    int l = 0;
    int r = height.size() - 1;
    int max_area = 0;
    int w = height.size() - 1;
    
    while (l < r) {
        int l_val = height[l];
        int r_val = height[r];
        int min_val = min(l_val, r_val);
        int area = min_val * w;
        
        // Update max area
        if (area > max_area) {
            max_area = area;
        }
        
        // Shift the pointer to min value
        if (l_val == min_val) {
            l++;
        } else {
            r--;
        }
        
        w--;
    }
    
    return max_area;
}
