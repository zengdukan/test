/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

#include <map>
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

class Solution
{

  public:
    int romanToInt(string s)
    {
        int ret = 0;
        const char* p = s.data();
        int l = 0;
        for (auto& [n, t]: valueSymbols) {
            while (strncmp(p, t.data(), t.length()) == 0) {
                ret += n;
                p += t.length();
                l += t.length();
            }

            if (l == s.length()) {
                break;
            }
        }

        return ret;
    }
};
// @lc code=end
