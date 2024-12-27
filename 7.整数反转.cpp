/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
#include <climits>
class Solution {
public:
    int reverse(int x) {
        int ret = 0;

        while (x != 0) {
            if (ret < INT_MIN / 10 || ret > INT_MAX / 10)
                return 0;
            int n = x % 10;
            x = x / 10;

            ret = ret * 10 + n;
        }

        return ret;;
    }
};
// @lc code=end

