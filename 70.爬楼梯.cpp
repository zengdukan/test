/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        int n_1 = 2;
        int n_2 = 1;
        int ret = 0;
        for (int i = 3; i <= n; i++) {
            ret = n_1 + n_2;
            n_2 = n_1;
            n_1 = ret;
        }

        return ret;
    }
};
// @lc code=end

