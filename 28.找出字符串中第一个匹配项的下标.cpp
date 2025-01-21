/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        return _strStr(haystack.c_str(), needle.c_str());
    }

    int _strStr(const char* haystack, const char* needle) {
        int haystack_len = strlen(haystack);
        int needle_len = strlen(needle);

        for (int i = 0; i <= haystack_len - needle_len; i++) {
            if (haystack[i] == needle[0]) {
                int j = 1;
                for (; j < needle_len; j++) {
                    if (haystack[i + j] != needle[j]) {
                        break;
                    }
                }

                if (j == needle_len) {
                    return i;
                }
            }
        }

        return -1;
    }
};
// @lc code=end

