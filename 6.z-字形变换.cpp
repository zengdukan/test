/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        vector<string> vs(numRows);

        int flag = 1;
        for (int i = 0, j = 0; i < s.length(); i++) {
            vs[j] += s[i];
            j += flag;

            if (j == (numRows - 1) || j == 0) {
                flag = -flag;
            }
        }

        string ret;
        for (auto& item : vs) {
            ret.append(item);
        }

        return ret;
    }
};
// @lc code=end

