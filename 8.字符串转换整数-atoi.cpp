/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

#include <climits>
#include <string>
#include <iostream>

using namespace std;

// @lc code=start
const int64_t max_int = (1LL << 31) - 1;
const int64_t min_int = (1LL << 31);

class Solution {
public:
    int myAtoi(string s) {
        return _myAtoi(s.c_str());
    }


    int _myAtoi(const char* s) {
        int ret = 0;
        int less_0 = 0;

        while ((*s == ' ') && *s != '\0') {
            s++;
        }

        if (*s == '-') {
            s++;
            less_0 = 1;
        } else if (*s == '+') {
            s++;
        } else if (*s < '0' || *s > '9') {
            return 0;
        }

        while ((*s == '0') && *s != '\0') {
            s++;
        }
        
        while (*s != '\0') {
            printf("%s:%d, %c, %d\n", __FUNCTION__, __LINE__, *s, ret);
            if (*s < '0' || *s > '9') {
                break;
            }

            int64_t tmp = ret;
            tmp = tmp * 10 + (*s - '0');
            if (less_0 && (tmp >= min_int)) {
                return -min_int;
            } else if (tmp >= max_int) {
                ret = max_int;
                break;
            } else {
                ret = tmp;
            }
            s++;
        }

        return less_0 ? -ret : ret;
    }
};
// @lc code=end

