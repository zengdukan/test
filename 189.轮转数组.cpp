/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        _rotate(nums, 0, nums.size() - 1);

        _rotate(nums, 0, k - 1);
        _rotate(nums, k, nums.size() - 1);
    }

    void _rotate(vector<int>& nums, int start, int end) {
        while (start < end) {
            std::swap(nums[start++], nums[end--]);
        }
    }
};
// @lc code=end

