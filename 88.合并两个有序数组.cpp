/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int r = m + n - 1;
        for (; i >= 0 && j >= 0; ) {
            if (nums1[i] > nums2[j]) {
                nums1[r--] = nums1[i--];
            } else {
                nums1[r--] = nums2[j--];
            }
        }

        for (; i >= 0; ) {
            nums1[r--] = nums1[i--];
        }
        for (; j >= 0; ) {
            nums1[r--] = nums2[j--];
        }
    }
};
// @lc code=end

