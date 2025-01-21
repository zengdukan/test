/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

#include <climits>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;

        int max_profit = 0;
        int min_price = prices[0];
        for (int m = 1; m < prices.size(); m++) {
            max_profit = std::max(max_profit, prices[m] - min_price);
            min_price = std::min(min_price, prices[m]);
        }

        return max_profit;
    }
};
// @lc code=end

