/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
        
        int n = prices.size();
        int profit[n][2];

        profit[0][0] = 0;
        profit[0][1] = -prices[0];

        for (int i = 1; i < n; i++) {
            profit[i][0] = std::max(profit[i - 1][0], profit[i - 1][1] + prices[i]);
            profit[i][1] = std::max(profit[i - 1][1], profit[i - 1][0] - prices[i]);
        }

        return profit[n - 1][0];
    }
};
// @lc code=end

