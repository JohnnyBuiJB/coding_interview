#include <vector>

using namespace std;

static int maxCrossArr(vector<int>& arr, int b, int m, int e) {
    // Divide the crossing arr to 2 parts by the mid point, L and R.
    // Notice that L has to contain arr[m] and R has to contain arr[m+1]
    // Max crossing arr = max(L) + max(R)
    
    // max L
    int max_l = 0;
    int sum = 0;
    for (auto i = m; i > b - 1; i--) {
        sum += arr[i];
        
        if (sum > max_l) {
            max_l = sum;
        }
    }
    
    // max R
    int max_r = 0;
    sum = 0;
    for (auto i = m + 1; i <= e; i++) {
        sum += arr[i];
        
        if (sum > max_r) {
            max_r = sum;
        }
    }
    
    return max_l + max_r;
}

/**
 * \Time    O(nlogn)
 * \Space   -
 * \Trick   Divide and conquer
 * \Ref     CLRS, page 68
 */
int maxSubArr(vector<int>& arr, int b, int e) {
    // Base case
    if (b == e) {
        return arr[b];
    }
    
    auto m = (b + e) / 2;
    
    // Calculate max crossing subarr
    int max_cross = maxCrossArr(arr, b, m, e);
    
    // Max left sub arr
    int max_left = maxSubArr(arr, b, m);
        
    // Max right sub arr
    int max_right = maxSubArr(arr, m + 1, e);
    
    int max = max_left;

    if (max_right > max) {
        max = max_right;
    } 
    
    if (max_cross > max) {
        max = max_cross;
    }

    return max;
}
