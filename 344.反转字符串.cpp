/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0;
        int h = s.size() - 1;
        while (l < h) {
            char tmp = s[l];
            s[l] = s[h];
            s[h] = tmp;

            l++;
            h--;
        }
    }
};
// @lc code=end

