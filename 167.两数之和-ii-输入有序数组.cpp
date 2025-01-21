/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0;
        int high = numbers.size() - 1;
        vector<int> ret;

        while (low < high) {
            int sum = numbers[low] + numbers[high];
            if (sum == target) {
                return vector<int>{low + 1, high + 1};
            } else if (sum > target) {
                high--;
            } else {
                low++;
            }
        }

        return ret;
    }
};
// @lc code=end

