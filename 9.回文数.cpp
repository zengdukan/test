/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

#include <string.h>
#include <stdio.h>

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        char buf[128] = {0};
        memset(buf, 0, sizeof(buf));

        sprintf(buf, "%d", x);
        int len = strlen(buf);
        int low = 0;
        int high = len - 1;
        while (low < high) {
            if (buf[low] != buf[high]) {
                return false;
            }
            low++;
            high--;
        }

        return true;
    }
};
// @lc code=end

