/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size() - 1);
        return nums;
    }
    void quick_sort(vector<int>& nums, int start, int end) {
        if (start >= end)
            return;

        int idx = partition(nums, start, end);
        quick_sort(nums, start, idx - 1);
        quick_sort(nums, idx + 1, end);
    }

    int partition(vector<int>& nums, int start, int end) {
        int key = nums[start];

        int low = start, high = end;
        while (low < high) {
            while (low < high && nums[high] >= key) {
                high--;
            }
            while (low < high && nums[low] <= key) {
                low++;
            }


            if (low < high)
                std::swap(nums[low], nums[high]);
            
        }

        std::swap(nums[start], nums[low]);
        return low;
    }
};
// @lc code=end

