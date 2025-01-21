/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size <= 2) {
            return size;
        }

        int low = 2;
        for (int high = 2; high < size; high++) {
            if (nums[high] != nums[low - 2]) {
                nums[low++] = nums[high];
            }
        }

        return low;
    }
};
// @lc code=end

