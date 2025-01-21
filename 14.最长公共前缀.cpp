/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret;

        int i = 0;
        while (true) {
            char c;
            int n = 0;
            for (n = 0; n < strs.size(); n++) {
                if (i >= strs[n].length())
                    break;

                if (n == 0) {
                    c = strs[n][i];
                    continue;
                }

                if (strs[n][i] != c)
                    break;
            }

            if (n != strs.size())
                break;
             
            i++;
            ret += c;
        }

        return ret;
    }
};
// @lc code=end

