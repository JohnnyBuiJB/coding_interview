/**
 * \Intuition: Use iterative DP
 * \Time: O(n)
 * \Space: O(1)
 * \Ref: Vy Bui
 */
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) {
            return 0;
        }

        if (n == 1) {
            return 1;
        }

        if (n == 2) {
            return 2;
        }

        int last_two[2];
        int pp = 0;     // previous previous
        int p = 1;      // previous

        // Start from i = 3
        last_two[pp] = 1;
        last_two[p] = 2;

        int num_ways;

        for (int i = 3; i <= n; i++) {
            num_ways = last_two[pp] + last_two[p];
            pp = (pp + 1) % 2;
            p = (p + 1) % 2;
            last_two[p] = num_ways;
        }

        return num_ways;
    }
};
