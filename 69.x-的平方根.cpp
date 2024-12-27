/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int start = 1;
        int end = x;
        while (start <= end) {
            long long mid = start + (end - start) / 2;
            long long mid2 = mid * mid;
            if (mid2 < x) {
                start = mid + 1;
            } else if (mid2 > x) {
                end = mid - 1;
            } else {
                return mid;
            }
        }

        return start - 1;
    }
};
// @lc code=end

