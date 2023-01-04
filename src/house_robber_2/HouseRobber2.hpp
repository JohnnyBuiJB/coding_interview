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

        if (n == 1) {
            return nums[0];
        }

        mpNums = &nums;
        auto max_wo_last = robDP(nums.size() - 1);

        auto first = nums[0];
        nums.erase(nums.begin());
        auto max_wo_first = robDP(nums.size());
        nums.insert(nums.begin(), first);

        return max(max_wo_first, max_wo_last);
    }

private:
    vector<int>* mpNums = nullptr;

    int robDP(int n) {
        auto nums = *mpNums;

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
