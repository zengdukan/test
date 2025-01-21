/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        int ret = 0, cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            ++counts[n];
            if (counts[n] > cnt) {
                ret = n;
                cnt = counts[n];
            }
        }

        return ret;
    }
};
// @lc code=end

