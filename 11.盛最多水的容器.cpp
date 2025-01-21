/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

#include <vector>
using namespace std;


// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = 0;

        for (int l = 0, h = height.size() - 1; l < h; ) {
            int area = std::min(height[l], height[h]) * (h - l);
            ret = std::max(area, ret);

            if (height[l] < height[h]) {
                l++;
            } else {
                h--;
            }
        }

        return ret;
    }
};
// @lc code=end

