/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, 0);

        int low = 0;
        int high = 0;
        int ret = 0;

        while (high < s.size()) {
            int& n = hash[s[high++]];
            n++;

            if (n <= 1)
                ret = std::max(ret, high - low);

            while (n > 1) {
                hash[s[low++]]--;
            }
        }

        return ret;
    }

    
};
// @lc code=end

