/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

#include <utility>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        quick_sort(nums, k, 0, nums.size() - 1);
        return nums[nums.size() - k];
    }

    void quick_sort(vector<int>& nums, int k, int start, int end) {
        if (start >= end)
            return;

        int idx = partition(nums, k, start, end);
        if (idx == (nums.size() - k)) {
            return;
        } else if ((nums.size() - k) > idx) {
            quick_sort(nums, k, idx + 1, end);
        } else {
            quick_sort(nums, k, start, idx - 1);
        }
    }

    int partition(vector<int>& nums, int k, int start, int end) {
        int key = nums[start];
        int low = start;
        int high = end;
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

