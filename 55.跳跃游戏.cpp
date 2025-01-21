/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int max_next = 0;
        for (int i = 0; i < size; i++) {
            if (i <= max_next) {
                max_next = std::max(max_next, i + nums[i]);
                if (max_next >= size - 1)
                    return true;
            }
        }

        return false;
    }
};
// @lc code=end

