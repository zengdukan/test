/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        string ret;
        char* data = s.data();
        int len = s.size();

        reverse(data, len);

        int i = 0;
        while (i < len) {
            while (i < len && data[i] == ' ') {
                i++;
            }

            char* start = data + i;
            int size = 0;
            while (i < len && data[i] != ' ') {
                i++;
                size++;
            }

            if (size == 0)
                continue;
            
            reverse(start, size);
        
            if (ret.empty())
                ret += string(start, size);
            else
                ret += " " + string(start, size);
        }

        return ret;
    }

    void reverse(char* data, int len) {
        int l = 0;
        int h = len - 1;

        while (l < h) {
            char t = data[l];
            data[l] = data[h];
            data[h] = t;

            l++;
            h--;
        }
    }
};
// @lc code=end

