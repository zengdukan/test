/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // return quick_sort(nums, 0, nums.size() - 1, val);
        int low = 0;
        int high = 0;
        // int key = nums[start];

        for (high = 0; high < nums.size(); high++) {
            if (nums[high] != val) {
                nums[low] = nums[high];
                low++;
            }
        }
        
        return low;
    }

    static void swap(int& a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
};
// @lc code=end

