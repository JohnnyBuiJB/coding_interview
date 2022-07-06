// https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1

#include <algorithm>

int minSwap(int arr[], int n, int k) {
    // Find count of elements less than equals to k
    int count = 0;
    for (int i = 0; i < n; ++i)
        if (arr[i] <= k)
            ++count;

    // Find unwanted elements in current window of size 'count'
    int n_bad = 0;
    for (int i = 0; i < count; ++i)
        if (arr[i] > k)
            ++n_bad;

    // Initialize answer with 'bad' value of current window
    int ans = n_bad;

    // Slide the window
    for (int i = 0, j = count; j < n; ++i, ++j) {
        // Decrement count of previous window
        if (arr[i] > k)
            --n_bad;

        // Increment count of current window
        if (arr[j] > k)
            ++n_bad;

        // Update ans if count of 'bad'
        // is less in current window
        ans = std::min(ans, n_bad);
    }

    return ans;
}
