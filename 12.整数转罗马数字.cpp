/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

#include <string>

using namespace std;

// @lc code=start
const pair<int, string> valueSymbols[] = {
    {1000, "M"},
    {900,  "CM"},
    {500,  "D"},
    {400,  "CD"},
    {100,  "C"},
    {90,   "XC"},
    {50,   "L"},
    {40,   "XL"},
    {10,   "X"},
    {9,    "IX"},
    {5,    "V"},
    {4,    "IV"},
    {1,    "I"},
};

class Solution {
public:
    string intToRoman(int num) {
        string ret;
        for (auto &[v, s] : valueSymbols) {
            while (num >= v) {
                num -= v;
                ret += s;
            }

            if (num == 0)
                break;
        }

        return ret;
    }
};
// @lc code=end

