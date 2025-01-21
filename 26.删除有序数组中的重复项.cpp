/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        int size = 1;

        for (int fast = 1; fast < nums.size(); fast++) {
            if (nums[fast] != nums[size - 1]) {
                nums[size++] = nums[fast];
            }
        }

        return size;
    }
};
// @lc code=end

