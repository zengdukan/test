/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty() || target < nums[0])
            return 0;

        int start = 0;
        int end = nums.size() - 1;
        int mid = 0;

        while (start <= end) {
            mid = (start + end) / 2;
            if (nums[mid] < target)
                start = mid + 1;
            else if (nums[mid] > target)
                end = mid - 1;
            else {
                break;
            }
        }

        if (nums[mid] >= target)
            return mid;
        else
            return start;
    }
};
// @lc code=end

