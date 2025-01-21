/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        const char* data = s.data();
        int len = s.size();

        int i = 0;
        for (i = len - 1; i >= 0 && data[i] == ' '; i--) {
            
        }

        int ret = 0;
        for (; i >= 0 && data[i] != ' '; i--, ret++) {

        }

        return ret;
    }
};
// @lc code=end

