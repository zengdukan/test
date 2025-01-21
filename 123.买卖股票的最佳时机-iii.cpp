/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy1_ = -prices[0];
        int sell1_ = 0;
        int buy2_ = -prices[0];
        int sell2_ = 0;
        int buy1 = buy1_;
        int buy2 = buy2_;
        int sell1 = sell1_;
        int sell2 = sell2_;

        for (int i = 1; i < n; i++) {
            buy1 = std::max(buy1_, -prices[i]);
            sell1 = std::max(sell1_, buy1_ + prices[i]);
            buy2 = std::max(buy2_, sell1_ - prices[i]);
            sell2 = std::max(sell2_, buy2_ + prices[i]);

            buy1_ = buy1;
            sell1_ = sell1;
            buy2_ = buy2;
            sell2_ = sell2;
        }

        return sell2;
    }
};
// @lc code=end

