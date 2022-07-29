#include <vector>

using namespace std;

/**
 * \Time    O(n)
 * \Space   O(1)
 * \Trick   Imagine the price chart as continuous up trends. An up trend starts 
 * from the lowest point and can go up or down, but never goes below the lowest 
 * point. The new lowest point (lower than the previous lowest point) signals 
 * the next up trend. We compare the profit of all these up trends and choose 
 * the maximum. Notice that an up trend can be 0 length (sell and buy at the 
 * same time) when there are continuous new lowest points.
 * \Ref     Neetcode
 */
int maxStockProfit(vector<int>& prices) {
    int max_pro = 0;

    int i_l = 0;
    int i_r = 1;

    while (i_r < prices.size()) {
        // Profitable
        if (prices[i_r] > prices[i_l]) {
            auto profit = prices[i_r] - prices[i_l];
            max_pro = max(max_pro, profit);
        } 
        // New lowest price signals the next possible up trend
        else {
            i_l = i_r;
        }
        i_r++;
    }

    return max_pro;
}
