#include <vector>

using namespace std;

/**
 * \Intuition: iterative DP
 * \Time: O(n)
 * \Space: O(1)
 * \Ref: Vy Bui
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // Trivial
        if (n <= 0) {
            return 0;
        }

        int next_max = 0;
        int next_next_max = 0;
        int max_amount;

        for (int i = n - 1; i >= 0; i--) {
            max_amount = max(nums[i] + next_next_max, next_max);
            next_next_max = next_max;
            next_max = max_amount;
        }

        return max_amount;
    }
};
