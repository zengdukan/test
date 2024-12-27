/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> sums(nums.size());
        
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || sums[i - 1] < 0)
                sums[i] = nums[i];
            else {
                sums[i] = sums[i - 1] + nums[i];
            }
        }

        int maxSum = sums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (maxSum < sums[i])
                maxSum = sums[i];
        }

        return maxSum;
    }
};
// @lc code=end

