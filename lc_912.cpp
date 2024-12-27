/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        //quick_sort(nums, 0, nums.size() - 1);
        merge_sort(nums, 0, nums.size() - 1);
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
        int low = start;
        int high = end;
        int key = nums[start];
        while (low < high) {
            while (low < high && nums[high] >= key) {
                high--;
            }
            while (low < high && nums[low] <= key) {
                low++;
            }

            swap(nums[low], nums[high]);
        }

        swap(nums[start], nums[low]);
        return low;
    }

    static void swap(int& a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    void merge_sort(vector<int>& nums, int start, int end) {
        if (start >= end)
            return;

        int mid = (end + start) / 2;
        merge_sort(nums, start, mid - 1);
        merge_sort(nums, mid , end);

        vector<int> tmp(end - start + 1);
        int l = start, r = mid, i = 0;

        for (; l < mid && r <= end; i++) {
            if (nums[l] < nums[r]) {
                tmp[i] = nums[l++];
            } else {
                tmp[i] = nums[r++];
            }
        }

        for (; l < mid; l++, i++)
            tmp[i] = nums[l];

        for (; r <= end; r++, i++)
            tmp[i] = nums[r];

        for (i = start; i <= end; i++)
            nums[i] = tmp[i - start];
    }
};
// @lc code=end

