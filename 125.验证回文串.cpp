/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isDigitChar(int c) {
        return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || ('0' <= c && c <= '9');
    }
    bool isPalindrome(string s) {
        int len = s.size();
        int low = 0;
        int high = len - 1;

        while (low < high) {
            if (!isDigitChar(s[low])) {
                low++;
                continue;
            }
            if (!isDigitChar(s[high])) {
                high--;
                continue;
            }

            int lowc = s[low] <= 'Z' ? s[low] + ('a' - 'A') : s[low];
            int highc = s[high] <= 'Z' ? s[high] + ('a' - 'A') : s[high];

            if (lowc != highc) {
                // printf("%d:%c  -- %d:%c\n", low, s[low], high, s[high]);
                return false;
            }

            low++;
            high--;
        }

        return true;
    }
};
// @lc code=end

