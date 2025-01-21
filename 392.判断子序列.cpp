/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len_s = s.size();
        int len_t = t.size();
        int is = 0;
        int it = 0;

        for (it = 0; it < len_t && is < len_s; it++) {
            if (s[is] == t[it]) {
                is++;
            }
        }
        
        return is == len_s;
    }
};
// @lc code=end

